#include "../../include/grid.hpp"
#include "../../include/mouse.hpp"

void Grid::setTexture(sf::RenderWindow &window, Mouse &mouse) {
  bool isPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

  for (size_t i = 0; i < tiles.size(); ++i) {
    if (tiles[i].getGlobalBounds().contains(mouse.mousePos(window)) &&
        mouse.getHoverState() == Mouse::HoverState::GRID && m_wasPressed &&
        !m_wasPressed) {
      tiles[i].setFillColor(std::get<sf::Color>(mouse.getContent()));
    }
  }

  m_wasPressed = isPressed;
}