#include "../../include/mouse.hpp"

void Mouse::update(Grid &grid, Sidebar &sidebar, sf::RenderWindow &window) {
  m_hoverState = checkHover(grid, sidebar, window);
}