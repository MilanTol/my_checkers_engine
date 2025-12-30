#include "../config.hpp"
#include "../position.hpp"

void drawWhiteChecker(sf::RenderWindow& window, int square)
{
        sf::CircleShape checker_img(cfg::checker_radius);

        int column = square% 10;
        int row = (square - column) / 10;
        sf::Vector2f position = {column * cfg::squareSize.x, row * cfg::squareSize.y};

        position += cfg::squareSize/2.0f; //add half a square to center the image on square
        position.x -= cfg::checker_radius;
        position.y -= cfg::checker_radius;
        checker_img.setPosition(position);

        checker_img.setFillColor(sf::Color::White);
        window.draw(checker_img);    
}

void drawBlackChecker(sf::RenderWindow& window, int square)
{
        sf::CircleShape checker_img(cfg::checker_radius);

        int column = square% 10;
        int row = (square - column) / 10;
        sf::Vector2f position = {column * cfg::squareSize.x, row * cfg::squareSize.y};

        position += cfg::squareSize/2.0f; //add half a square to center the image on square
        position.x -= cfg::checker_radius;
        position.y -= cfg::checker_radius;
        checker_img.setPosition(position);

        checker_img.setFillColor(sf::Color::Black);
        window.draw(checker_img);    
}

void drawCheckers(sf::RenderWindow& window, Position position)
{
    for (int i = 0; i < 100; i++)
    {
        if (position.whiteSquares[i])
        {
            drawWhiteChecker(window, i);
        }
        if (position.blackSquares[i])
        {
            drawBlackChecker(window, i);
        }
    }
    
}

