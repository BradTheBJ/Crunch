#include "../../include/sidebar.hpp"

Sidebar::Sidebar(unsigned int width, unsigned int height, sf::Vector2f pos,
                 sf::Color color, unsigned int boxWidth, unsigned int boxHeight,
                 const Content &content)
    : m_width(width), m_height(height), m_pos(pos), m_color(color), m_boxWidth(boxWidth),
      m_boxHeight(boxHeight), m_content(content) {
  sidebarRect.setSize(sf::Vector2f(width, height));
  sidebarRect.setOrigin(sf::Vector2f(width / 2, height / 2));
  sidebarRect.setFillColor(color);
  sidebarRect.setPosition(pos);
}