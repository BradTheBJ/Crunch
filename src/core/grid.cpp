#include "../../include/core/grid.hpp"
#include "../../include/core/mouse.hpp"

Grid::Grid(unsigned int colWidth, unsigned int colHeight,
           unsigned int tileSizeX, unsigned int tileSizeY, double gap)
    : m_ColWidth(colWidth), m_ColHeight(colHeight), m_gap(gap),
      m_wasPressed(false) {
  m_tile.setSize(sf::Vector2f(tileSizeX, tileSizeY));
  m_tile.setOrigin(sf::Vector2f(tileSizeX / 2.f, tileSizeY / 2.f));

  for (size_t y = 0; y < m_ColHeight; ++y) {
    for (size_t x = 0; x < m_ColWidth; ++x) {
      sf::RectangleShape t = m_tile;
      t.setPosition(sf::Vector2f(
          x * (m_tile.getSize().x + m_gap) + m_tile.getSize().x / 2.f,
          y * (m_tile.getSize().y + m_gap) + m_tile.getSize().y / 2.f));
      m_tiles.push_back(t);
      m_tileColors.push_back(sf::Color::White);
    }
  }
}

void Grid::setTexture(sf::RenderWindow &window) {
  bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
  Mouse mouse(sf::Color::Red);

  for (size_t i = 0; i < m_tiles.size(); ++i) {
    if (m_tiles[i].getGlobalBounds().contains(mouse.mousePos(window)) &&
        isPressed && !m_wasPressed) {
      m_tiles[i].setFillColor(std::get<sf::Color>(mouse.getContent()));
    }
  }

  m_wasPressed = isPressed;
}

void Grid::update(sf::RenderWindow &window) { setTexture(window); }

void Grid::draw(sf::RenderWindow &window) {
  for (auto &t : m_tiles) {
    window.draw(t);
  };
}
