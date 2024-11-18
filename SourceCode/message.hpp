#pragma once

#include "gameObject.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <functional>

#include "scene.hpp"

class Message : public GameObject {

private:
	sf::Text text;
	sf::Font& font;
	sf::RectangleShape shape;
	std::string messageText;
	bool isVisible;

	std::function<void()> action;

public:
	Message(std::string identifier, sf::Font& font, std::string messageText,
		sf::Vector2f size, sf::Color color);
	~Message();

	void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
	virtual void onClick();

	void update() override;
	void render (sf::RenderWindow& window) override;

	std::string getMessageText() const;
	void setButtonAction(std::function<void()> action);
	void setCharacterSize(const int size);
	void setPosition(const sf::Vector2f position);
	void setMessage(std::string messageText);
	void setVisible(bool isVisible);
};