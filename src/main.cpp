#include <SFML/Graphics.hpp>
#include <iostream>

#include "events.hpp"
#include "input.hpp"

#include "config.hpp"
#include "checker.hpp"
#include "square.hpp"

#include "position.hpp"
#include "dynamic_position.hpp"
#include "legal_moves.hpp"

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

Position position = Position();
DynamicPosition dynamic_position = DynamicPosition(position);

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

            dynamic_position.move(clicked_square, released_square);
            position = dynamic_position.position;
            
            clicked_square = -1;
            input.mouseClicked = false;
            input.mouseReleased = false;
        }
        
        window.clear();

        drawBoard(window);

        // drawCheckers(window, black_checkers);
        // drawCheckers(window, white_checkers);
        drawCheckers(window, position);


        window.display();
    }
}
