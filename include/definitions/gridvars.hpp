#pragma once

#include <SFML/Graphics.hpp>

struct GridVars {
  unsigned int colWidth = 8;
  unsigned int colHeight = 8;
  unsigned int tileSizeX = 50;
  unsigned int tileSizeY = 50;
  double gap = 5.0;
  sf::Color color = sf::Color::White;
};
