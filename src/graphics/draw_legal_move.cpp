#include "../config.hpp"
#include "../board/position.hpp"
#include "../board/moves/move.hpp"

void drawLegalMove(sf::RenderWindow& window, Move move)
{
        sf::CircleShape dot_img(cfg::checker_radius / 3.0f);

        int column = move.destination.square_id% 10;
        int row = (move.destination.square_id - column) / 10;
        sf::Vector2f position = {column * cfg::squareSize.x, row * cfg::squareSize.y};

        position += cfg::squareSize/2.0f; //add half a square to center the image on square
        position.x -= cfg::checker_radius/3.0f;
        position.y -= cfg::checker_radius/3.0f;
        dot_img.setPosition(position);

        dot_img.setFillColor(sf::Color(128, 128, 128));
        //dot_img.setFillColor(sf::Color::Green);
        window.draw(dot_img);    
}


