#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <variant>

class Sidebar {
public:
  using Content = std::variant<sf::Color, std::string>;

  Sidebar(unsigned int width, unsigned int height, sf::Vector2f pos,
          sf::Color color, unsigned int boxWidth, unsigned int boxHeight,
          const Content &content);

  void update(sf::RenderWindow &window);
  void draw(sf::RenderWindow &window);

  const sf::RectangleShape &getSidebar() const { return m_sidebar; }
  sf::RectangleShape m_sidebar;

private:
  unsigned int width;
  unsigned int height;
  sf::Vector2f pos;
  sf::Color color;
  unsigned int boxWidth;
  unsigned int boxHeight;
  Content content;
};
