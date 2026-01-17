#include "../../include/core/window.hpp"
#include "../../include/core/grid.hpp"
#include "../../include/core/mouse.hpp"
#include "../../include/core/sidebar.hpp"
#include "../../include/definitions/gridvars.hpp"
#include "../../include/definitions/sidebarvars.hpp"

Window::Window(const std::string &title, bool vsync)
    : m_title(title), m_vsync(vsync) {
  m_window.create(sf::VideoMode::getDesktopMode(), m_title);
  if (m_vsync) {
    m_window.setVerticalSyncEnabled(true);
  }
}

void Window::display() {
  Mouse mouse(sf::Color::Red);
  GridVars gridVars;
  SidebarVars sidebarVars;
  sf::Vector2u windowSize = m_window.getSize();
  sidebarVars.height = windowSize.y;
  sidebarVars.position = sf::Vector2f(windowSize.x - sidebarVars.width / 2.0f,
                                      sidebarVars.height / 2.0f);
  Sidebar sidebar(sidebarVars.width, sidebarVars.height, sidebarVars.position,
                  sidebarVars.color, sidebarVars.boxWidth,
                  sidebarVars.boxHeight, sidebarVars.boxContent);
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
    mouse.update(grid, sidebar, m_window);
    grid.update(m_window, mouse);
    grid.draw(m_window);
    sidebar.draw(m_window);
    sidebar.update(m_window);
    m_window.display();
  }
}
