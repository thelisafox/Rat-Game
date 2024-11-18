#include "message.hpp"

#include <SFML/Window/Event.hpp>

Message::Message(std::string identifier, sf::Font& font, std::string messageText,
	sf::Vector2f size, sf::Color color) : GameObject(identifier), font(font), messageText(messageText)
{
	this->shape.setSize(size);
    this->shape.setSize(size);
    this->shape.setFillColor(color);
    this->shape.setOutlineColor(sf::Color::Black);
    this->shape.setOutlineThickness(1);

    this->text.setFont(font);
    this->text.setString(messageText);
    this->text.setCharacterSize(26);
    this->text.setFillColor(sf::Color::White);

    sf::FloatRect textRect = this->text.getLocalBounds();
    this->text.setOrigin(textRect.left + textRect.width / 2.0f , textRect.top + textRect.height / 2.0f);

    this->setPosition(sf::Vector2f(0.0f, 0.0f));
}

Message::~Message() { }

void Message::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Button::Left) {

        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        sf::Vector2f size = shape.getSize();
        sf::Vector2f position = shape.getPosition();

        if (mousePosition.x >= position.x && mousePosition.x <= position.x + size.x &&
            mousePosition.y >= position.y && mousePosition.y <= position.y + size.y) {
            this->onClick();
        }
    }
}

void Message::update() { }

std::string Message::getMessageText() const {
    return this->messageText;
}

void Message::setCharacterSize(const int size) {
    this->text.setCharacterSize(size);
}   

void Message::setPosition(const sf::Vector2f position) {
    this->shape.setPosition(position);
    sf::Vector2f size = this->shape.getSize();
    sf::Vector2f centerButton(position.x + (size.x / 2.0f), position.y + (size.y / 2.0f));
    this->text.setPosition(centerButton);
}

void Message::onClick() {
    this->action();
}

void Message::setButtonAction(std::function<void()> action) {
    this->action = action;
}

void Message::setMessage(std::string messageText) {
    this->messageText = messageText;
    this->text.setString(this->messageText);
}

void Message::setVisible(bool isVisible) {
    this->isVisible = isVisible;
    isVisible = false;
}

void Message::render(sf::RenderWindow& window) {
    if (isVisible == true) {
        window.draw(this->shape);
        window.draw(this->text);
    }
}
