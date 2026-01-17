#pragma once

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Logs {
public:
  virtual ~Logs() = default;

  virtual void setMessages(std::vector<std::string>& messages) = 0;

  virtual void displayLogs(const std::vector<std::string>& messages,
                           sf::RenderWindow& window) = 0;
};
