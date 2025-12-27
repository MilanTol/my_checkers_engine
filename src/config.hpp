#pragma once

#include <SFML/Graphics.hpp>

namespace cfg
{
//window configuration
sf::Vector2u const window_size =  {1000, 1000};
sf::Vector2f const window_size_f = {1000.0f, 1000.0f};

//squares
sf::Vector2f const squareSize = 1.0f/10.0f * cfg::window_size_f;

//checkers configuration
double const checker_radius = 25;
}

