#include <SFML/Graphics.hpp>

#include "events.hpp"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Let's play checkers!");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        processEvents(window);
        
        window.clear();
        window.display();
    }
}
