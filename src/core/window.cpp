#include "../../include/core/window.hpp"
#include "../../include/core/grid.hpp"

Window::Window(const std::string &title, bool vsync)
    : title(title), vsync(vsync) {
  window.create(sf::VideoMode::getDesktopMode(), title);
  if (vsync) {
    window.setVerticalSyncEnabled(true);
  }
}

void Window::display() {
  Grid grid(20, 20, 64, 64, 1);
  while (window.isOpen()) {
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
