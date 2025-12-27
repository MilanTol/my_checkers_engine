

#include "../config.hpp"

void drawBoard(sf::RenderWindow& window)
{
    sf::Vector2f squareSize = 1.0f/10.0f * cfg::window_size_f;

    for (int i=0; i<100; i++)
    {   
        int row = i % 10;
        int column = (i - row) / 10;
        
        //determine rectanglesize
        sf::RectangleShape square(squareSize);
        //determine rectangle position
        sf::Vector2f position = {row * squareSize.x, column * squareSize.y};
        square.setPosition(position);

        //color square
        if ((column + row) % 2)
            square.setFillColor(sf::Color(139, 69, 19)); //color dark
        else
            square.setFillColor(sf::Color(222, 184, 135)); //color light

        window.draw(square);
    }
}