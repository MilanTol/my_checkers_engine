

#include "../config.hpp"

void drawBoard(sf::RenderWindow& window)
{
    for (int i=0; i<100; i++)
    {   
        //determine rectanglesize
        sf::RectangleShape square(cfg::squareSize);
        
        //determine rectangle position
        int column = i % 10;
        int row = (i - column) / 10;
        sf::Vector2f position = {row * cfg::squareSize.x, column * cfg::squareSize.y};
        square.setPosition(position);

        //color square
        if ((column + row) % 2)
            square.setFillColor(sf::Color(139, 69, 19)); //color dark
        else
            square.setFillColor(sf::Color(222, 184, 135)); //color light

        window.draw(square);
    }
}