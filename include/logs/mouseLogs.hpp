#pragma once

#include "logs.hpp"
#include "mouse.hpp"

class MouseLogs : public Logs {
public:
  MouseLogs();

  void setMessages(std::vector<std::string>& messages) override;

  void displayLogs(const std::vector<std::string>& messages,
                   sf::RenderWindow& window) override;
};
