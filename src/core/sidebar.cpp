#include "../../include/core/sidebar.hpp"

void Sidebar::draw(sf::RenderWindow &window) { window.draw(m_sidebar); }

void Sidebar::update(sf::RenderWindow &window) { draw(window); }
