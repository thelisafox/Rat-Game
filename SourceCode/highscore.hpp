#include <iostream>
#include <fstream>
#include <istream>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include "gameObject.hpp"

class highScore : public GameObject {
	private:
		std::vector<int> highScores;
		sf::Font& font;
		sf::Text text;
		std::string textStr;
		sf::Vector2f position;
		std::ifstream highScoreTXT;
		std::ofstream highScoreTXTout;

		//int score;

	public:
		highScore(std::string identifier, sf::Font& font, std::string textStr);
		~highScore();

		void update() override;
		void render(sf::RenderWindow& window) override;

		void setFile();
		std::string getTextStr() const;
		void setText(const std::string textStr);
		std::string getText() const;
		void setCharacterSize(const int size);
		void setFillColor(const sf::Color color);
		void setPosition(const sf::Vector2f position);
		void setScoreText();
		void clear();
		void add(int score);
};