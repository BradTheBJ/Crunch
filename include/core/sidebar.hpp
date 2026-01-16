#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <variant>

class Sidebar {
public:
  using Content = std::variant<sf::Color, std::string>;

  Sidebar(unsigned int width, unsigned int height, sf::Color color,
          unsigned int boxWidth, unsigned int boxHeight, const Content &content);

  void update(sf::RenderWindow &window);
  void draw(sf::RenderWindow &window);

private:
  unsigned int m_width;
  unsigned int m_height;
  unsigned int m_boxWidth;
  unsigned int m_boxHeight;
  Content m_content;
  sf::RectangleShape m_sidebar;
  sf::Color m_color;
};
