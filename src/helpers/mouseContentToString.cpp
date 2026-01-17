#include <sstream>
#include "../../include/helpers/mouseContentToString.hpp"

std::string contentToString(const std::variant<sf::Color, std::string>& content) {
  return std::visit([](const auto& value) -> std::string {
    using T = std::decay_t<decltype(value)>;

    if constexpr (std::is_same_v<T, sf::Color>) {
      std::ostringstream oss;
      oss << "RGBA("
          << static_cast<int>(value.r) << ", "
          << static_cast<int>(value.g) << ", "
          << static_cast<int>(value.b) << ", "
          << static_cast<int>(value.a) << ")";
      return oss.str();
    } else if constexpr (std::is_same_v<T, std::string>) {
      return value;
    }
  }, content);
}
