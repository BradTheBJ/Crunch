#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Mouse;

class Grid {
public:
  Grid(unsigned int colWidth, unsigned int colHeight, unsigned int tileSizeX,
       unsigned int tileSizeY, double gap);

  void update(sf::RenderWindow &window, Mouse &mouse);
  void setTexture(sf::RenderWindow &window, Mouse &mouse);
  void draw(sf::RenderWindow &window);

  const std::vector<sf::RectangleShape> &getTiles() const { return tiles; }
  std::vector<sf::RectangleShape> tiles;

private:
  unsigned int m_colWidth;
  unsigned int m_colHeight;
  double m_gap;
  sf::RectangleShape m_tile;
  std::vector<sf::Color> m_tileColors;
  bool m_wasPressed;
};
