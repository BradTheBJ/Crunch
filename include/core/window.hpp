#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Window {
public:
  Window(const std::string &title, bool vsync);
  void display();

private:
  std::string title;
  bool vsync;
  sf::RenderWindow window;
};
