#include "../../include/core/grid.hpp"

Grid::Grid(unsigned int colWidth, unsigned int colHeight,
           unsigned int tileSizeX, unsigned int tileSizeY, double gap)
    : ColWidth(colWidth), ColHeight(colHeight), gap(gap), wasPressed(false) {
  tile.setSize(sf::Vector2f(tileSizeX, tileSizeY));
  tile.setOrigin(sf::Vector2f(tileSizeX / 2.f, tileSizeY / 2.f));

  for (size_t y = 0; y < ColHeight; ++y) {
    for (size_t x = 0; x < ColWidth; ++x) {
      sf::RectangleShape t = tile;
      t.setPosition(
          sf::Vector2f(x * (tile.getSize().x + gap) + tile.getSize().x / 2.f,
                       y * (tile.getSize().y + gap) + tile.getSize().y / 2.f));
      tiles.push_back(t);
      tileColors.push_back(sf::Color::White);
    }
  }
}
// This is only temporary code
void Grid::setTexture(sf::RenderWindow &window) {
  sf::Vector2f mousePos =
      window.mapPixelToCoords(sf::Mouse::getPosition(window));

  bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

  for (size_t i = 0; i < tiles.size(); ++i) {
    if (tiles[i].getGlobalBounds().contains(mousePos) && isPressed && !wasPressed) {
      // Toggle color on click
      if (tileColors[i] == sf::Color::White) {
        tileColors[i] = sf::Color::Red;
      } else {
        tileColors[i] = sf::Color::White;
      }
    }
    tiles[i].setFillColor(tileColors[i]);
  }

  wasPressed = isPressed;
}

void Grid::update(sf::RenderWindow &window) {
  setTexture(window);
}

void Grid::draw(sf::RenderWindow &window) {
  for (auto &t : tiles) {
    window.draw(t);
  }
}
