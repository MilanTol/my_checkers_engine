#include <SFML/Graphics.hpp>

#include "events.hpp"
#include "config.hpp"
#include "graphics/draw_board.hpp"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({cfg::window_size.x, cfg::window_size.y}), "Let's play checkers!");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        processEvents(window);
        
        window.clear();

        drawBoard(window);

        window.display();
    }
}
