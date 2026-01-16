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
  unsigned int m_ColWidth;
  unsigned int m_ColHeight;
  unsigned int m_gap;
  sf::RectangleShape m_tile;
  std::vector<sf::RectangleShape> m_tiles;
  std::vector<sf::Color> m_tileColors;
  bool m_wasPressed;
};
