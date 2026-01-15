#include "../../include/core/window.hpp"
#include "../../include/core/grid.hpp"
#include "../../include/definitions/gridvars.hpp"

Window::Window(const std::string &title, bool vsync)
    : title(title), vsync(vsync) {
  window.create(sf::VideoMode::getDesktopMode(), title);
  if (vsync) {
    window.setVerticalSyncEnabled(true);
  }
}

void Window::display() {
  while (window.isOpen()) {
    GridVars gridVars;
    Grid grid(gridVars.colWidth, gridVars.colHeight, gridVars.tileSizeX,
              gridVars.tileSizeY, gridVars.gap);
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    window.clear(sf::Color::Black);
    grid.update(window);
    window.display();
  }
}
