#include "../../include/grid.hpp"
#include "../../include/mouse.hpp"

void Grid::update(sf::RenderWindow &window, Mouse &mouse) {
  setTexture(window, mouse);
}