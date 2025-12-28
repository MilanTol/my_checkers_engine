#include <SFML/Graphics.hpp>
#include <iostream>

#include "events.hpp"
#include "input.hpp"

#include "config.hpp"
#include "checker.hpp"
#include "emptySquares.hpp"

#include "graphics/draw_board.hpp"
#include "graphics/draw_checkers.hpp"

std::vector<Checker> init_black()
{
    std::vector<Checker> black_checkers;

    //init black checkers
    for (int i=0; i<20; i++)
    {   
        int square = 1 + 2*i;
        int column = square % 10;
        int row = (square - column) / 10;
        if (row%2)
        {
            square -= 1; 
        }
        black_checkers.push_back(Checker(square, 0));
    }
    return black_checkers;
}

std::vector<Checker> init_white()
{
    std::vector<Checker> white_checkers;

    //init white checkers
    for (int i=0; i<20; i++)
    {   
        int square = 99 - 2*i;
        int column = square % 10;
        int row = (square - column) / 10;
        if (row%2)
        {
            square -= 1;
        }
        white_checkers.push_back(Checker(square, 1));
    }
    return white_checkers;
}

int positionToSquare(sf::Vector2i position)
{
    int column = static_cast<int>( position.x / (cfg::window_size.x/10) ); //this rounds down in c++
    int row = static_cast<int>( position.y / (cfg::window_size.y/10) );
    return 10*row + column;
}

Input input;
int selected_checker = -1;
EmptySquares empty_squares;

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({cfg::window_size.x, cfg::window_size.y}), "Let's play checkers!");
    window.setFramerateLimit(60);

    std::vector<Checker> black_checkers = init_black();
    std::vector<Checker> white_checkers = init_white();
    
    std::vector<Checker> checkers = black_checkers; 
    checkers.insert(checkers.end(), white_checkers.begin(), white_checkers.end());

    while (window.isOpen())
    {   
        processEvents(window, input);
        
        if (input.mouseClicked and selected_checker == -1) // if clicked
        {   
            int clicked_square = positionToSquare(sf::Mouse::getPosition(window));

            for (int i = 0; i < checkers.size(); i++)
            {
                if (checkers[i].square == clicked_square)
                {
                    selected_checker = i;
                    break;
                }
            }
        }

        if (input.mouseReleased and selected_checker != -1) //if released
        {
            int released_square = positionToSquare(sf::Mouse::getPosition(window));
            if (empty_squares.isEmpty(released_square)) //is move.legal()
            {
                empty_squares.setEmpty(checkers[selected_checker].square, true); //empty previous square of checker
                checkers[selected_checker].square = released_square; //update checker square
                empty_squares.setEmpty(checkers[selected_checker].square, false); //fill destination square of checker
            }
            selected_checker = -1;
            input.mouseClicked = false;
            input.mouseReleased = false;
        }
        
        window.clear();

        drawBoard(window);

        // drawCheckers(window, black_checkers);
        // drawCheckers(window, white_checkers);
        drawCheckers(window, checkers);


        window.display();
    }
}
