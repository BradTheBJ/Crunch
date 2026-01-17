#include "../../include/definitions/gridvars.hpp"
#include "../../include/definitions/sidebarvars.hpp"
#include "../../include/grid.hpp"
#include "../../include/logs/mouseLogs.hpp"
#include "../../include/mouse.hpp"
#include "../../include/sidebar.hpp"
#include "../../include/window.hpp"

void Window::display() {
  Mouse mouse(sf::Color::Red);
  GridVars gridVars;
  SidebarVars sidebarVars;
  MouseLogs mouseLogs;
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
    std::vector<std::string> messages;
    mouseLogs.setMessages(messages);
    mouseLogs.displayLogs(messages, m_window);
    m_window.clear(sf::Color::Black);
    mouse.update(grid, sidebar, m_window);
    grid.update(m_window, mouse);
    grid.draw(m_window);
    sidebar.draw(m_window);
    sidebar.update(m_window);
    m_window.display();
  }
}
