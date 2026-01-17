#pragma once

#include <SFML/Graphics.hpp>

struct GridVars {
  std::string title = "Crunch";
  unsigned int colWidth = 28;
  unsigned int colHeight = 16;
  unsigned int tileSizeX = 64;
  unsigned int tileSizeY = 64;
  double gap = 5.0;
  sf::Color color = sf::Color::White;
};
