#pragma once

#include <SFML/Graphics.hpp>
#include <variant>
#include <string>

struct Mouse {
    using MouseContent = std::variant<sf::Color, std::string>;

    Mouse(const sf::Color& color)
        : m_mouseContent(color) {}

    Mouse(const std::string& spriteFilepath)
        : m_mouseContent(spriteFilepath) {}

    sf::Vector2f mousePos(sf::RenderWindow& window) const {
        return window.mapPixelToCoords(sf::Mouse::getPosition(window));
    }

    bool isLeftButtonPressed() const {
        return sf::Mouse::isButtonPressed(sf::Mouse::Left);
    }

    bool isRightButtonPressed() const {
        return sf::Mouse::isButtonPressed(sf::Mouse::Right);
    }

    bool isMiddleButtonPressed() const {
        return sf::Mouse::isButtonPressed(sf::Mouse::Middle);
    }

    bool isScrollUp(const sf::Event& event) const {
        return event.type == sf::Event::MouseWheelScrolled &&
               event.mouseWheelScroll.delta > 0;
    }

    bool isScrollDown(const sf::Event& event) const {
        return event.type == sf::Event::MouseWheelScrolled &&
               event.mouseWheelScroll.delta < 0;
    }

    void setColor(const sf::Color& color) {
        m_mouseContent = color;
    }

    void setSprite(const std::string& spriteFilepath) {
        m_mouseContent = spriteFilepath;
    }

    const MouseContent& getContent() const {
        return m_mouseContent;
    }

private:
    MouseContent m_mouseContent;
};
