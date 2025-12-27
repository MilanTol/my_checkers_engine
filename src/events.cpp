#include <SFML/Graphics.hpp>

void processEvents(sf::Window& window)
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                window.close();
        }
    }   
}

bool mouseClicked(sf::Window& window)
{
    while (const std::optional event = window.pollEvent())
    {
        if (const auto* keyPressed = event->getIf<sf::Event::MouseButtonPressed>())
        {   
            if (keyPressed->button == sf::Mouse::Button::Left)
            {
                return 1;
            }
        }
    }  
}
