#include "../../include/logs/mouseLogs.hpp"
#include "../../include/helpers/mouseContentToString.hpp"
#include <iostream>

MouseLogs::MouseLogs() : Logs() {}

void MouseLogs::setMessages(std::vector<std::string>& messages) {
  messages.push_back("Mouse position:");
  messages.push_back("Mouse content:");
  //messages.push_back("Mouse is hovering over:");
}

void MouseLogs::displayLogs(const std::vector<std::string>& messages,
                            sf::RenderWindow& window) {
  Mouse mouse(sf::Color::White);
  // Mouse mouse("Sprite: cursor.png");

  sf::Vector2f pos = mouse.mousePos(window);

  std::cout << messages[0]
            << " (" << pos.x << ", " << pos.y << ")\n";

  std::cout << messages[1]
            << " " << contentToString(mouse.getContent()) << '\n';
}

