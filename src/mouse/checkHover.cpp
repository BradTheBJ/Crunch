#include "../../include/mouse.hpp"

Mouse::HoverState Mouse::checkHover(Grid &grid, Sidebar &sidebar,
                                    sf::RenderWindow &window) {
  if (sidebar.sidebarRect.getGlobalBounds().contains(
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