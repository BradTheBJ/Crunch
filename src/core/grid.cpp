#include "../../include/core/grid.hpp"

Grid::Grid(unsigned int colWidth, unsigned int colHeight,
           unsigned int tileSizeX, unsigned int tileSizeY, double gap)
    : ColWidth(colWidth), ColHeight(colHeight), gap(gap) {
  tile.setSize(sf::Vector2f(tileSizeX, tileSizeY));
  tile.setOrigin(sf::Vector2f(tileSizeX / 2.f, tileSizeY / 2.f));

  for (size_t y = 0; y < ColHeight; ++y) {
    for (size_t x = 0; x < ColWidth; ++x) {
      sf::RectangleShape t = tile;
      t.setPosition(
          sf::Vector2f(x * (tile.getSize().x + gap) + tile.getSize().x / 2.f,
                       y * (tile.getSize().y + gap) + tile.getSize().y / 2.f));
      t.setFillColor(sf::Color::White);
      tiles.push_back(t);
    }
  }
}
// This is only temporary code
void Grid::setTexture(sf::RenderWindow &window) {
  sf::Vector2f mousePos =
      window.mapPixelToCoords(sf::Mouse::getPosition(window));

  for (auto &t : tiles) {
    if (t.getGlobalBounds().contains(mousePos) &&
        sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      t.setFillColor(sf::Color::Red);
    } else {
      t.setFillColor(sf::Color::White);
    }
  }
}

void Grid::update(sf::RenderWindow &window) {
  setTexture(window);
  for (auto &t : tiles) {
    window.draw(t);
  }
}
