#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Grid {
public:
  Grid(unsigned int colWidth, unsigned int colHeight, unsigned int tileSizeX,
       unsigned int tileSizeY, double gap);

  void update(sf::RenderWindow &window);
  void setTexture(sf::RenderWindow &window);
  void draw(sf::RenderWindow &window);

private:
  unsigned int ColWidth;
  unsigned int ColHeight;
  unsigned int gap;
  sf::RectangleShape tile;
  std::vector<sf::RectangleShape> tiles;
  std::vector<sf::Color> tileColors;
  bool wasPressed;
};
