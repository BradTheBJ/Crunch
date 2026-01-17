#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <variant>

struct SidebarVars {
  unsigned int width = 200;
  unsigned int height = 600; // Will be overridden by window height
  sf::Vector2f position = sf::Vector2f(800, 300);
  sf::Color color = sf::Color::Black;
  unsigned int boxWidth = 180;
  unsigned int boxHeight = 50;
  std::variant<sf::Color, std::string> boxContent = sf::Color::Red;
};
