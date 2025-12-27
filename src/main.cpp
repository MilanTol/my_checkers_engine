#include <SFML/Graphics.hpp>
#include <iostream>
#include "events.hpp"
#include "config.hpp"
#include "checker.hpp"
#include "graphics/draw_board.hpp"
#include "graphics/draw_checkers.hpp"

std::vector<Checker> init_position()
{
    std::vector<Checker> checkers;
    //init black checkers
    for (int i=0; i<20; i++)
    {   
        int square = 2*i;
        int row = (2*i) % 10;
        std::cout << row << std::endl;
        if (!row%2)
        {
            square += 1; 
        }
        
        checkers.push_back(Checker(square, 0));
    }
    //init white checkers
    for (int i=0; i<20; i++)
    {
        checkers.push_back(Checker(99 - 2*i, 1));
    }
    return checkers;
}


int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({cfg::window_size.x, cfg::window_size.y}), "Let's play checkers!");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        processEvents(window);
        
        window.clear();

        std::vector<Checker> checkers = init_position();
        
        drawBoard(window);
        drawCheckers(window, checkers);

        window.display();
    }
}
