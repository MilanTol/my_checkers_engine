#pragma once

#include <SFML/Graphics.hpp>

namespace cfg
{
//window configuration
sf::Vector2u const window_size =  {600, 600};
sf::Vector2f const window_size_f = {600.0f, 600.0f};

//squares
sf::Vector2f const squareSize = 1.0f/10.0f * cfg::window_size_f;

//checkers configuration
double const checker_radius = window_size_f.x/40.0;
}

