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


int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({cfg::window_size.x, cfg::window_size.y}), "Let's play checkers!");
    window.setFramerateLimit(60);

    std::vector<Checker> black_checkers = init_black();
    std::vector<Checker> white_checkers = init_white();

    while (window.isOpen())
    {
        processEvents(window);
        
        window.clear();

        drawBoard(window);
        drawCheckers(window, black_checkers);
        drawCheckers(window, white_checkers);

        window.display();
    }
}
