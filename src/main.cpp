#include <SFML/Graphics.hpp>
#include <iostream>
#include "events.hpp"
#include "config.hpp"
#include "checker.hpp"
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
    int column = static_cast<int>(position.x / cfg::window_size.x); //this rounds down in c++
    int row = static_cast<int>(position.y / cfg::window_size.y);
    return 10*row + column;
}

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
        processEvents(window);
        if (mouseClicked(window))
        {
            sf::Vector2i clicked_point = sf::Mouse::getPosition(window); 
            int clicked_square = positionToSquare(clicked_point);
            int selected_checker_index = -1;
            for (int i = 0; i < checkers.size(); i++)
            {
                if (checkers[i].square == clicked_square)
                    selected_checker_index = i;
            }
        }

        window.clear();

        drawBoard(window);

        // drawCheckers(window, black_checkers);
        // drawCheckers(window, white_checkers);
        drawCheckers(window, checkers);


        window.display();
    }
}
