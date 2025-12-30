#include <SFML/Graphics.hpp>
#include <iostream>

#include "user_interface/events.hpp"
#include "user_interface/input.hpp"

#include "config.hpp"

#include "board/square.hpp"
#include "board/position.hpp"
#include "board/dynamic_position.hpp"
#include "board/legal_moves.hpp"

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

DynamicPosition position = DynamicPosition(Position());

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
        }

        if (input.mouseReleased and clicked_square != -1) //if released
        {   
            int released_square = positionToSquare(sf::Mouse::getPosition(window));

            position.move(clicked_square, released_square);
                        
            clicked_square = -1;
            input.mouseClicked = false;
            input.mouseReleased = false;
        }
        
        window.clear();

        drawBoard(window);
        drawCheckers(window, position);

        window.display();
    }
}
