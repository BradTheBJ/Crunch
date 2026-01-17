#pragma once
#include <SFML/Graphics.hpp>
#include <variant>
#include <string>

std::string contentToString(const std::variant<sf::Color, std::string>& content);