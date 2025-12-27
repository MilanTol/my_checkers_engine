#include "../config.hpp"
#include "../checker.hpp"

void drawCheckers(sf::RenderWindow& window, std::vector<Checker> checkers)
{
    for (Checker& checker : checkers)
    {         
        sf::CircleShape checker_img(cfg::checker_radius);

        //set position
        int column = checker.square% 10;
        int row = (checker.square - column) / 10;
        sf::Vector2f position = {row * cfg::squareSize.x, column * cfg::squareSize.y};
        position += cfg::squareSize/2.0f; //add half a square to center the image on square
        position.x -= cfg::checker_radius;
        position.y -= cfg::checker_radius;
        checker_img.setPosition(position);

        //set color
        if (checker.color){ //set white color
            checker_img.setFillColor(sf::Color::White);
        }
        else {
            checker_img.setFillColor(sf::Color::Black);
        }

        window.draw(checker_img);
    }
}