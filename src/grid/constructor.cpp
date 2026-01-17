#include "../../include/grid.hpp"

Grid::Grid(unsigned int colWidth, unsigned int colHeight,
           unsigned int tileSizeX, unsigned int tileSizeY, double gap)
    : m_colWidth(colWidth), m_colHeight(colHeight), m_gap(gap), m_wasPressed(false) {
  m_tile.setSize(sf::Vector2f(tileSizeX, tileSizeY));
  m_tile.setOrigin(sf::Vector2f(tileSizeX / 2.f, tileSizeY / 2.f));

  for (size_t y = 0; y < m_colHeight; ++y) {
    for (size_t x = 0; x < m_colWidth; ++x) {
      sf::RectangleShape t = m_tile;
      t.setPosition(
          sf::Vector2f(x * (m_tile.getSize().x + m_gap) + m_tile.getSize().x / 2.f,
                       y * (m_tile.getSize().y + m_gap) + m_tile.getSize().y / 2.f));
      tiles.push_back(t);
      m_tileColors.push_back(sf::Color::White);
    }
  }
}