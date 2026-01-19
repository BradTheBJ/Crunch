#include "../../include/helpers/mouseHoverToString.hpp"

std::string hoverToString(Mouse& mouse) {
    switch (mouse.getHoverState()) {
        case Mouse::HoverState::SIDEBAR:
            return "SIDEBAR";
        case Mouse::HoverState::GRID:
            return "GRID";
        case Mouse::HoverState::NONE:
            return "NONE";
        default:
            return "UNKNOWN";
    }
}

