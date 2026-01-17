#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <variant>

class Sidebar {
public:
  using Content = std::variant<sf::Color, std::string>;

  Sidebar(unsigned int width, unsigned int height, sf::Color color,
          unsigned int boxWidth, unsigned int boxHeight, const Content &content)
      : m_width(width), m_height(height), m_color(color), m_boxWidth(boxWidth),
        m_boxHeight(boxHeight), m_content(content) {
    m_sidebar.setSize(sf::Vector2f(m_width, m_height));
    m_sidebar.setOrigin(sf::Vector2f(m_width / 2, m_height / 2));
    m_sidebar.setFillColor(m_color);
  }

  void update(sf::RenderWindow &window);
  void draw(sf::RenderWindow &window);

private:
  unsigned int m_width;
  unsigned int m_height;
  sf::Color m_color;
  unsigned int m_boxWidth;
  unsigned int m_boxHeight;
  Content m_content;
  sf::RectangleShape m_sidebar;
};
