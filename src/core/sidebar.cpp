#include "../../include/core/sidebar.hpp"

Sidebar::Sidebar(unsigned int width, unsigned int height, sf::Vector2f pos, sf::Color color,
                 unsigned int boxWidth, unsigned int boxHeight, const Content &content)
    : m_width(width), m_height(height), m_pos(pos), m_color(color), m_boxWidth(boxWidth),
      m_boxHeight(boxHeight), m_content(content) {
  m_sidebar.setSize(sf::Vector2f(m_width, m_height));
  m_sidebar.setOrigin(sf::Vector2f(m_width / 2, m_height / 2));
  m_sidebar.setFillColor(m_color);
  m_sidebar.setPosition(m_pos);
}

void Sidebar::draw(sf::RenderWindow &window) { window.draw(m_sidebar); }

void Sidebar::update(sf::RenderWindow &window) { draw(window); }
