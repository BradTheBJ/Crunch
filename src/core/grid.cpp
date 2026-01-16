#include "../../include/core/grid.hpp"
#include "../../include/core/mouse.hpp"

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
  bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
  Mouse mouse(sf::Color::Magenta);
  
  for (size_t i = 0; i < tiles.size(); ++i) {
    if (tiles[i].getGlobalBounds().contains(mouse.mousePos(window)) && isPressed && !wasPressed) {
      tiles[i].setFillColor(std::get<sf::Color>(mouse.getContent()));
    }
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
