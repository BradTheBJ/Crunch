#include "../../include/grid.hpp"

void Grid::draw(sf::RenderWindow &window) {
  for (auto t : tiles) {
    window.draw(t);
  };
}