#include "../../include/window.hpp"

Window::Window(const std::string &title, bool vsync)
    : m_title(title), m_vsync(vsync) {
  m_window.create(sf::VideoMode::getDesktopMode(), m_title);
  if (m_vsync) {
    m_window.setVerticalSyncEnabled(true);
  }
}