#include "../config.hpp"
#include "../board/position.hpp"

void drawWhiteKing(sf::RenderWindow& window, int square)
{
    sf::CircleShape king_img(cfg::checker_radius);

    int column = square% 10;
    int row = (square - column) / 10;
    sf::Vector2f position = {column * cfg::squareSize.x, row * cfg::squareSize.y};

    position += cfg::squareSize/2.0f; //add half a square to center the image on square
    position.x -= cfg::checker_radius;
    position.y -= cfg::checker_radius;
    king_img.setPosition(position);

    king_img.setFillColor(sf::Color::White);
    window.draw(king_img); 

    //draw crown
    sf::CircleShape crown_img(cfg::checker_radius/2);

    position.x += cfg::checker_radius/2;
    position.y += cfg::checker_radius/2;
    crown_img.setPosition(position);
    
    crown_img.setFillColor(sf::Color::Blue);
    window.draw(crown_img);
}

void drawWhiteKing(sf::RenderWindow& window, sf::Vector2i position)
{
    sf::CircleShape king_img(cfg::checker_radius);

    sf::Vector2f position_f;
    position_f.x = position.x;
    position_f.y = position.y;

    position_f.x -= cfg::checker_radius;
    position_f.y -= cfg::checker_radius;
    king_img.setPosition(position_f);

    king_img.setFillColor(sf::Color::White);
    window.draw(king_img); 

    //draw crown
    sf::CircleShape crown_img(cfg::checker_radius/2);

    position_f.x += cfg::checker_radius/2;
    position_f.y += cfg::checker_radius/2;
    crown_img.setPosition(position_f);
    
    crown_img.setFillColor(sf::Color::Blue);
    window.draw(crown_img);
}

void drawBlackKing(sf::RenderWindow& window, int square)
{
    sf::CircleShape king_img(cfg::checker_radius);

    int column = square% 10;
    int row = (square - column) / 10;
    sf::Vector2f position = {column * cfg::squareSize.x, row * cfg::squareSize.y};

    position += cfg::squareSize/2.0f; //add half a square to center the image on square
    position.x -= cfg::checker_radius;
    position.y -= cfg::checker_radius;
    king_img.setPosition(position);

    king_img.setFillColor(sf::Color::Black);
    window.draw(king_img); 

    //draw crown
    sf::CircleShape crown_img(cfg::checker_radius/2);

    position.x += cfg::checker_radius/2;
    position.y += cfg::checker_radius/2;
    crown_img.setPosition(position);
    
    crown_img.setFillColor(sf::Color::Red);
    window.draw(crown_img);
}

void drawBlackKing(sf::RenderWindow& window, sf::Vector2i position)
{
    sf::CircleShape king_img(cfg::checker_radius);

    sf::Vector2f position_f;
    position_f.x = position.x;
    position_f.y = position.y;

    position_f.x -= cfg::checker_radius;
    position_f.y -= cfg::checker_radius;
    king_img.setPosition(position_f);

    king_img.setFillColor(sf::Color::Black);
    window.draw(king_img); 

    //draw crown
    sf::CircleShape crown_img(cfg::checker_radius/2);

    position_f.x += cfg::checker_radius/2;
    position_f.y += cfg::checker_radius/2;
    crown_img.setPosition(position_f);
    
    crown_img.setFillColor(sf::Color::Red);
    window.draw(crown_img);
}


void drawKings(sf::RenderWindow& window, Position position)
{
    for (int i = 0; i < 100; i++)
    {
        if (position.isWhiteKing(Square(i)))
        {
            drawWhiteKing(window, i);
        }
        if (position.isBlackKing(Square(i)))
        {
            drawBlackKing(window, i);
        }
    }
}
