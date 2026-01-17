#include "../../include/core/mouse.hpp"

void Mouse::update(Grid &grid, Sidebar &sidebar, sf::RenderWindow &window) {
  m_hoverState = checkHover(grid, sidebar, window);
}

Mouse::HoverState Mouse::checkHover(Grid &grid, Sidebar &sidebar,
                                    sf::RenderWindow &window) {
  if (sidebar.m_sidebar.getGlobalBounds().contains(
          mousePos(window))) { // This must be above all other checks so that
                               // sidebar takes priority
    return HoverState::SIDEBAR;
  }

  for (auto &tile : grid.getTiles()) {
    if (tile.getGlobalBounds().contains(mousePos(window))) {
      return HoverState::GRID;
    }
  }
  return HoverState::NONE;
}
