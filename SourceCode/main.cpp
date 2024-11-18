#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <fstream>
#include <iostream>
#include <chrono>
#include <thread>

#include "sceneHandler.hpp"
#include "scene.hpp"
#include "textObject.hpp"
#include "spriteObject.hpp"
#include "character.hpp"
#include "button.hpp"
#include "enemy.hpp"
#include "message.hpp"
#include "highscore.hpp"

using namespace std;

void characterAttackItself() {
    //GameObject& character = scene.getGameObjectByName("character");
    //Make the character attack it self
    printf("Hello world!\n");
}


int main() {
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML with Scenes!");
    SceneHandler handler;

    bool enemyTurn = false;
    bool gameover = false;
    int xp = 0;

    sf::Font font;
    font.loadFromFile("Lato-Regular.ttf");
    sf::Color darkColor = sf::Color(71, 82, 94, 255);
    sf::Color darkGreyColor = sf::Color(132, 146, 166, 255);
    sf::Color lightGreyColor = sf::Color(129, 144, 165, 255);

    Scene mainMenu("mainMenu");
    TextObject oleg("olegText", font, "Oleg");
    oleg.setPosition(sf::Vector2f(109.0f, 34.0f));
    oleg.setCharacterSize(26);
    oleg.setFillColor(darkColor);

    Button quitButton("quitButton", font, "QUIT", sf::Vector2f(192.5f, 50.0f), darkColor);
    quitButton.setPosition(sf::Vector2f(108.0f, 540.0f));
    quitButton.setButtonAction([&window]() {
        window.close();
        }
    );

    highScore HighScore("HighScore", font, "HighScores:\n");
    HighScore.setPosition(sf::Vector2f(708.0f, 470.0f));
    HighScore.setCharacterSize(26);
    HighScore.setFillColor(darkColor);
    HighScore.setFile();
    HighScore.setScoreText();
    HighScore.setText(HighScore.getText());

    Button eraseData("eraseData", font, "ERASE", sf::Vector2f(192.5f, 50.0f), darkColor);
    eraseData.setPosition(sf::Vector2f(108.0f, 640.0f));
    eraseData.setButtonAction([&HighScore]() {
        HighScore.clear();
        HighScore.setText(HighScore.getText());
        }
    );

    Button startButton("startButton", font, "START", sf::Vector2f(192.5f, 50.0f), darkColor);
    startButton.setPosition(sf::Vector2f(108.0f, 470.0f));
    startButton.setButtonAction([&handler]() {
        handler.stackScene("characterScreen");
        }
    );

    Scene characterScreen("characterScreen");
    Character character("Current character:", "rat_small.png", 5, 2, 1);

    TextObject characterName("characterNameText", font, "Current character: ");
    characterName.setPosition(sf::Vector2f(109.0f, 34.0f));
    characterName.setCharacterSize(26);
    characterName.setFillColor(darkColor);

    SpriteObject characterAvatar("soldierSprite", character.getSpriteFile());
    characterAvatar.setPosition(sf::Vector2f(128.0f, 100.0f));

    TextObject hpText("hpText", font, "HP: " + std::to_string(character.getHP()));
    hpText.setPosition(sf::Vector2f(161.0f, 238.0f));
    hpText.setCharacterSize(26);
    hpText.setFillColor(darkColor);

    TextObject attackText("attackText", font, "ATTACK: " + std::to_string(character.getAttack()));
    attackText.setPosition(sf::Vector2f(148.0f, 290.0f));
    attackText.setCharacterSize(26);
    attackText.setFillColor(darkColor);

    TextObject defenseText("defenseText", font, "DEFENSE: " + std::to_string(character.getDefense()));
    defenseText.setPosition(sf::Vector2f(140.0f, 345.0f));
    defenseText.setCharacterSize(26);
    defenseText.setFillColor(darkColor);

    SpriteObject character1_avatar("smallRat", "rat_small.png");
    character1_avatar.setPosition(sf::Vector2f(428.0f, 100.0f));
    
    Button character1_load("loadButton", font, "SMALL RAT", sf::Vector2f(192.5f, 50.0f), darkColor);
    character1_load.setPosition(sf::Vector2f(450.0f, 270.0f));

    character1_load.setButtonAction([&characterAvatar, &character, &characterName, &hpText, &attackText, &defenseText]() {
        std::ifstream myfileRead("small_rat.txt");
        if (!myfileRead.fail()) {
            std::string line;

            std::getline(myfileRead, line);
            character.setName(line);
            characterName.setText(line);

            std::getline(myfileRead, line);
            character.setHP(std::stoi(line));
            hpText.setText("HP: " + std::to_string(character.getHP()));

            std::getline(myfileRead, line);
            character.setAttack(std::stoi(line));
            attackText.setText("ATTACK: " + std::to_string(character.getAttack()));

            std::getline(myfileRead, line);
            character.setDefense(std::stoi(line));
            defenseText.setText("DEFENSE: " + std::to_string(character.getDefense()));
            myfileRead.close();

            character.setSpriteFile("rat_small.png");
            characterAvatar.setSprite(character.getSpriteFile());
        }
        });

    /*
    TextObject character2_name("characterNameText", font, "Long rat");
    character2_name.setPosition(sf::Vector2f(420.0f, 34.0f));
    character2_name.setCharacterSize(26);
    character2_name.setFillColor(darkColor);

    TextObject character2_hpText("hpText", font, "HP: " + std::to_string(10));
    character2_hpText.setPosition(sf::Vector2f(450.0f, 238.0f));
    character2_hpText.setCharacterSize(26);
    character2_hpText.setFillColor(darkColor);

    TextObject character2_attackText("attackText", font, "ATTACK: " + std::to_string(4));
    character2_attackText.setPosition(sf::Vector2f(450.0f, 290.0f));
    character2_attackText.setCharacterSize(26);
    character2_attackText.setFillColor(darkColor);

    TextObject character2_defenseText("defenseText", font, "DEFENSE: " + std::to_string(1));
    character2_defenseText.setPosition(sf::Vector2f(450.0f, 345.0f));
    character2_defenseText.setCharacterSize(26);
    character2_defenseText.setFillColor(darkColor);
    */

    SpriteObject character2_avatar("longRat", "rat_jump.png");
    character2_avatar.setPosition(sf::Vector2f(728.0f, 75.0f));

    Button loadButton("loadButton", font, "LONG RAT", sf::Vector2f(192.5f, 50.0f), darkColor);
    loadButton.setPosition(sf::Vector2f(700.0f, 270.0f));

    loadButton.setButtonAction([&characterAvatar, &character, &characterName, &hpText, &attackText, &defenseText]() {
        std::ifstream myfileRead("long_rat.txt");
        if (!myfileRead.fail()) {
            std::string line;

            std::getline(myfileRead, line);
            character.setName(line);
            characterName.setText(line);

            std::getline(myfileRead, line);
            character.setHP(std::stoi(line));
            hpText.setText("HP: " + std::to_string(character.getHP()));

            std::getline(myfileRead, line);
            character.setAttack(std::stoi(line));
            attackText.setText("ATTACK: " + std::to_string(character.getAttack()));

            std::getline(myfileRead, line);
            character.setDefense(std::stoi(line));
            defenseText.setText("DEFENSE: " + std::to_string(character.getDefense()));
            myfileRead.close();

            character.setSpriteFile("rat_jump.png");
            characterAvatar.setSprite(character.getSpriteFile());
        }
        });


    SpriteObject character3_avatar("bigRat", "big_rat.png");
    character3_avatar.setPosition(sf::Vector2f(928.0f, 75.0f));

    Button character3_load("loadButton", font, "BIG RAT", sf::Vector2f(192.5f, 50.0f), darkColor);
    character3_load.setPosition(sf::Vector2f(1000.0f, 270.0f));

    character3_load.setButtonAction([&characterAvatar, &character, &characterName, &hpText, &attackText, &defenseText]() {
        std::ifstream myfileRead("rat_big.txt");
        if (!myfileRead.fail()) {
            std::string line;

            std::getline(myfileRead, line);
            character.setName(line);
            characterName.setText(line);

            std::getline(myfileRead, line);
            character.setHP(std::stoi(line));
            hpText.setText("HP: " + std::to_string(character.getHP()));

            std::getline(myfileRead, line);
            character.setAttack(std::stoi(line));
            attackText.setText("ATTACK: " + std::to_string(character.getAttack()));

            std::getline(myfileRead, line);
            character.setDefense(std::stoi(line));
            defenseText.setText("DEFENSE: " + std::to_string(character.getDefense()));

            character.setSpriteFile("big_rat.png");
            characterAvatar.setSprite(character.getSpriteFile());

            myfileRead.close();
        }
        });

    Button playButton("playButton", font, "PLAY", sf::Vector2f(192.5f, 50.0f), darkColor);
    playButton.setPosition(sf::Vector2f(308.0f, 670.0f));
    playButton.setButtonAction([&handler]() {
        handler.stackScene("fightScene");
        }
    );

    Scene fightScene("fightScene");

    Enemy enemy("EvilRat", "head.png", 10, 2, 4, 1);

    TextObject enemyName("enemyNameText", font, enemy.getName());
    enemyName.setPosition(sf::Vector2f(809.0f, 34.0f));
    enemyName.setCharacterSize(26);
    enemyName.setFillColor(darkColor);

    SpriteObject enemyAvatar("soldierSprite", enemy.getSpriteFile());
    enemyAvatar.setPosition(sf::Vector2f(835.0f, 90.0f));
    enemyAvatar.setScale(sf::Vector2f(2.5f, 2.5f));

    TextObject hpTextEnemy("hpTextEnemy", font, "HP: " + std::to_string(enemy.getHP()));
    hpTextEnemy.setPosition(sf::Vector2f(809.0f, 238.0f));
    hpTextEnemy.setCharacterSize(26);
    hpTextEnemy.setFillColor(darkColor);

    Message message("message", font, "0", sf::Vector2f(1500, 200), darkColor);
    message.setPosition(sf::Vector2f(100, 800));
    message.setButtonAction([&message]() {
        message.setVisible(false);
     });

    Button attackButton("attackButton", font, "ATTACK",
        sf::Vector2f(192.5f, 50.0f), darkColor);
    attackButton.setPosition(sf::Vector2f(108.0f, 400.0f));
    //attackButton.setVisible(false);
    attackButton.setButtonAction([&enemyName, &xp, &gameover, &hpText, &character, &enemy, &hpTextEnemy, &enemyTurn, &attackButton, &message, &handler]() {
        if (enemyTurn == false) {
            int damage = character.attackCharacter(character);
            enemy.takeDamage(damage);
            hpTextEnemy.setText("HP: " + std::to_string(enemy.getHP()));
            message.setVisible(true);
            message.setMessage("You attacked the enemy and dealt " + std::to_string(damage) + " damage");
            if ((enemy.getHP()) > 0) { enemyTurn = true; }
            else { 
                message.setVisible(true);
                message.setMessage("You have killed an enemy!");
                gameover = true;
                xp += 150;

                enemy.setHP(10 + rand() % 6);
                hpTextEnemy.setText("HP: " + std::to_string(enemy.getHP()));

                enemy.setName("EvilRat " + std::to_string(rand() % 1000));
                enemyName.setText(enemy.getName());

                enemy.setAttack(1 + rand() % 2);
                enemy.setDefense(1 + rand() % 2);
            }
        }
        });

    Button healButton("healButton", font, "HEAL", sf::Vector2f(192.5f, 50.0f), darkColor);
    healButton.setPosition(sf::Vector2f(108.0f, 470.0f));
    healButton.setButtonAction([&character, &enemyTurn, &hpText, &message]() {
        if (enemyTurn == false) {
            int damage = character.attackCharacter(character);
            character.takeDamage(-damage);
            hpText.setText("HP: " + std::to_string(character.getHP()));
            message.setVisible(true);
            message.setMessage("You have gained " + std::to_string(damage) + " HP");
            enemyTurn = true;

        }
    });
    
    Scene gameOver("gameOver");

    handler.addScene(mainMenu);
    handler.addScene(characterScreen);
    handler.addScene(fightScene);
    handler.addScene(gameOver);

    Button backButton("backButton", font, "QUIT", sf::Vector2f(192.5f, 50.0f), darkColor);
    backButton.setPosition(sf::Vector2f(1600.0f, 50.0f));
    backButton.setButtonAction([&handler, &mainMenu]() {
        handler.stackScene("mainMenu");
        });

    mainMenu.addGameObject(oleg);
    mainMenu.addGameObject(quitButton);
    mainMenu.addGameObject(startButton);
    mainMenu.addGameObject(HighScore);
    mainMenu.addGameObject(eraseData);
    
    characterScreen.addGameObject(characterName);
    characterScreen.addGameObject(playButton);
    characterScreen.addGameObject(characterAvatar);
    characterScreen.addGameObject(hpText);
    characterScreen.addGameObject(attackText);
    characterScreen.addGameObject(defenseText);
    characterScreen.addGameObject(character2_avatar);
    characterScreen.addGameObject(character1_avatar);
    characterScreen.addGameObject(character1_load);
    characterScreen.addGameObject(character3_avatar);
    characterScreen.addGameObject(character3_load);
    /*
    characterScreen.addGameObject(character2_name);
    characterScreen.addGameObject(character2_hpText);
    characterScreen.addGameObject(character2_attackText);
    characterScreen.addGameObject(character2_defenseText);
    */
    characterScreen.addGameObject(loadButton);
    characterScreen.addGameObject(quitButton);

    fightScene.addGameObject(characterName);
    fightScene.addGameObject(message);
    fightScene.addGameObject(characterAvatar);
    fightScene.addGameObject(attackButton);
    fightScene.addGameObject(healButton);
    fightScene.addGameObject(hpText);
    fightScene.addGameObject(enemyName);
    fightScene.addGameObject(enemyAvatar);
    fightScene.addGameObject(hpTextEnemy);
    fightScene.addGameObject(backButton);

    gameOver.addGameObject(backButton);
    gameOver.addGameObject(message);

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else {
                handler.handleEvent(event, window);
            }
        }

        if (enemyTurn == true) { 
            attackButton.setPosition(sf::Vector2f(-1008.0f, 400.0f));
            healButton.setPosition(sf::Vector2f(-1008.0f, 470.0f));
        }

        window.clear(sf::Color::White);
        handler.update();
        handler.render(window);
        window.display();

        if (gameover == true) {
            
            std::this_thread::sleep_for(std::chrono::seconds(1));
            gameover = false;
        }

        if (enemyTurn == true) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            enemy.setAction();
            int damage = enemy.attackEnemy(enemy);
            character.takeDamage(damage);
            std::cout << damage;
            if (damage == 0) {
                message.setMessage("Enemy trembles in fear");
   
            }
            else { message.setMessage("Enemy dealt you " + std::to_string(damage) + " damage"); }
        }
            hpText.setText("HP: " + std::to_string(character.getHP()));
            if ((character.getHP()) <= 0) {
                message.setVisible(true);
                message.setMessage("You received " + std::to_string(xp) + " score!");
                HighScore.add(xp);
                HighScore.setScoreText();
                HighScore.setText(HighScore.getText());
                handler.stackScene("gameOver");
                character.setHP(10);
            }
            else {
                
                attackButton.setPosition(sf::Vector2f(108.0f, 400.0f));
                healButton.setPosition(sf::Vector2f(108.0f, 470.0f));
            }   
            enemyTurn = false;
    }

    return 0;
}





