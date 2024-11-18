#include "highscore.hpp"

highScore::highScore(std::string identifier, sf::Font& font, std::string textStr) : GameObject(identifier), font(font), textStr(textStr) {
    this->text.setString(this->textStr);
    this->text.setPosition(this->position);
    this->text.setFont(this->font);
    this->text.setCharacterSize(12);
    this->text.setFillColor(sf::Color::Black);
}

highScore::~highScore() { }

void highScore::update() { }

void highScore::render(sf::RenderWindow& window) {
    window.draw(this->text);
}

std::string highScore::getTextStr() const {
    return this->textStr;
}

void highScore::setText(const std::string textStr) {
    this->textStr = textStr;
    this->text.setString(this->textStr);
}

std::string highScore::getText() const {
    return this->textStr;
}

void highScore::setCharacterSize(const int size) {
    this->text.setCharacterSize(size);
}

void highScore::setFillColor(const sf::Color color) {
    this->text.setFillColor(color);
}

void highScore::setPosition(const sf::Vector2f position) {
    this->text.setPosition(position);
}

void highScore::setFile() {
    this->highScoreTXT.open("highscore.txt");
    
    std::string line;
    while (std::getline(highScoreTXT, line)) {
        this->highScores.push_back(std::stoi(line));
    }
    highScoreTXT.close();
}


void highScore::add(int score){
    std::sort(this->highScores.begin(), this->highScores.end());
    for (int i = 0; i < this->highScores.size(); i++) {
        if (score > this->highScores[i]) {
            this->highScores[i] = score;
            break;
        }
    }
    std::sort(this->highScores.begin(), this->highScores.end());
    this->highScoreTXTout.open("highscore.txt");
    std::string line;
    for (int i = 0; i < this->highScores.size(); i++) {
        this->highScoreTXTout << std::to_string(this->highScores[i]) <<"\n";
    }
    this->highScoreTXTout.close();

}
void highScore::setScoreText() {
    this->textStr = " ";
    for (int i = 0; i < this->highScores.size(); i++) {
        this->textStr += std::to_string(this->highScores[i]) + "\n";
    }
}

void highScore::clear() {
    this->textStr = " ";
    this->highScoreTXTout.open("highscore.txt");
    std::string line;
    for (int i = 0; i < this->highScores.size(); i++) {
        this->highScoreTXTout << "0" << "\n";
    }
    this->highScoreTXTout.close();
    for (int i = 0; i < this->highScores.size(); i++) {
        this->highScores[i] = 0;
        this->textStr += std::to_string(this->highScores[i]) + "\n";
    }
}