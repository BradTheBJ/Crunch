#include "../../include/core/window.hpp"

Window::Window(const std::string &title, bool vsync)
    : title(title), vsync(vsync) {
  window.create(sf::VideoMode::getDesktopMode(), title);
  if (vsync) {
    window.setVerticalSyncEnabled(true);
  }
}

void Window::display() {
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    window.clear(sf::Color::Black);
    window.display();
  }
}
