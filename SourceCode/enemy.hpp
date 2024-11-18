#pragma once

#include <string>

class Enemy {
private:
    std::string name;
    std::string spriteFile;
    int hp;
    int attack;
    int defense;
    int counter;
    bool action = true;

public:
    Enemy(std::string name, std::string spriteFile,
        int hp, int attack, int defense, int counter);
    ~Enemy();

    int attackEnemy(const Enemy& enemy) const;
    bool takeDamage(int damage);

    int getAttack() const;
    void setAttack(int attack);

    int getDefense() const;
    void setDefense(int defense);

    int getHP() const;
    void setHP(int hp);

    std::string getName() const;
    void setName(std::string name);

    std::string getSpriteFile() const;

    int getCounter() const;
    void setCounter(int counter);

    bool setAction();

    /*
    bool EnemyTurn(bool EnemyTurn);
    */
};
