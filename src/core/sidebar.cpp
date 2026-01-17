#include "../../include/core/sidebar.hpp"

Sidebar::Sidebar(unsigned int width, unsigned int height, sf::Vector2f pos,
                 sf::Color color, unsigned int boxWidth, unsigned int boxHeight,
                 const Content &content)
    : width(width), height(height), pos(pos), color(color), boxWidth(boxWidth),
      boxHeight(boxHeight), content(content) {
  m_sidebar.setSize(sf::Vector2f(width, height));
  m_sidebar.setOrigin(sf::Vector2f(width / 2, height / 2));
  m_sidebar.setFillColor(color);
  m_sidebar.setPosition(pos);
}

void Sidebar::draw(sf::RenderWindow &window) { window.draw(m_sidebar); }
void Sidebar::update(sf::RenderWindow &window) { draw(window); }
