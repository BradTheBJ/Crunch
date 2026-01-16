#include "../../include/core/window.hpp"
#include "../../include/core/grid.hpp"
#include "../../include/core/sidebar.hpp"
#include "../../include/definitions/gridvars.hpp"

Window::Window(const std::string &title, bool vsync)
    : m_title(title), m_vsync(vsync) {
  m_window.create(sf::VideoMode::getDesktopMode(), m_title);
  if (m_vsync) {
    m_window.setVerticalSyncEnabled(true);
  }
}

void Window::display() {
  GridVars gridVars;
  Sidebar sidebar(500, 500, sf::Color::Black, 50, 50, sf::Color::Blue);
  Grid grid(gridVars.colWidth, gridVars.colHeight, gridVars.tileSizeX,
            gridVars.tileSizeY, gridVars.gap);
  while (m_window.isOpen()) {
    sf::Event event;
    while (m_window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        m_window.close();
      }
    }
    m_window.clear(sf::Color::Black);
    grid.update(m_window);
    grid.draw(m_window);
    sidebar.draw(m_window);
    sidebar.update(m_window);
    m_window.display();
  }
}
