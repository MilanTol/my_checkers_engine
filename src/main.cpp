#include <SFML/Graphics.hpp>
#include <iostream>

#include "events.hpp"
#include "input.hpp"

#include "config.hpp"
#include "checker.hpp"
#include "emptySquares.hpp"

#include "position.hpp"
#include "legal_moves.hpp"
#include "square.hpp"

#include "graphics/draw_board.hpp"
#include "graphics/draw_checkers.hpp"

int positionToSquare(sf::Vector2i position)
{
    int column = static_cast<int>( position.x / (cfg::window_size.x/10) ); //this rounds down in c++
    int row = static_cast<int>( position.y / (cfg::window_size.y/10) );
    return 10*row + column;
}

Input input;
int clicked_square = -1;
EmptySquares empty_squares;

Position position = Position();

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({cfg::window_size.x, cfg::window_size.y}), "Let's play checkers!");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {   
        processEvents(window, input);
        
        if (input.mouseClicked and clicked_square == -1) // if clicked
        {   
            clicked_square = positionToSquare(sf::Mouse::getPosition(window));
            LegalMoves legal_moves = LegalMoves(clicked_square, position);
            std::cout << legal_moves.moveLeft << std::endl;

        }

        // if (input.mouseReleased and selected_checker != -1) //if released
        // {
        //     int released_square = positionToSquare(sf::Mouse::getPosition(window));
        //     if (empty_squares.isEmpty(released_square)) //is move.legal()
        //     {
        //         empty_squares.setEmpty(checkers[selected_checker].square, true); //empty previous square of checker
        //         checkers[selected_checker].square = released_square; //update checker square
        //         empty_squares.setEmpty(checkers[selected_checker].square, false); //fill destination square of checker
        //     }
        //     selected_checker = -1;
        //     input.mouseClicked = false;
        //     input.mouseReleased = false;
        // }
        
        window.clear();

        drawBoard(window);

        // drawCheckers(window, black_checkers);
        // drawCheckers(window, white_checkers);
        drawCheckers(window, position);


        window.display();
    }
}
