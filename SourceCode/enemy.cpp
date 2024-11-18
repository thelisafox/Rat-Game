#pragma once

#include "enemy.hpp"

#include <algorithm>
#include <iostream>

Enemy::Enemy(std::string name, std::string spriteFile, 
    int hp, int attack, int defense, int counter) :
    name(name), spriteFile(spriteFile), hp(hp), attack(attack), defense(defense), counter(counter)
{ }

Enemy::~Enemy() { }

bool Enemy::setAction() {
    //this->action = action;
    int chance = rand() % 4;
    if (chance < 1) { action = false; }
    else { action = true; }
    return action;

}

int Enemy::attackEnemy(const Enemy& enemy) const {

    int attackPower = attack + rand() % 4;
    int defensePower = enemy.getDefense() + (-1 + rand() % 3);
    return std::max(attackPower - defensePower, 0);
}

bool Enemy::takeDamage(int damage) {
    hp = std::max(hp - damage, 0);
    return hp == 0;
}

int Enemy::getAttack() const {
    return this->attack;
}

int Enemy::getCounter() const {
    return this->counter;
}

void Enemy::setAttack(int attack) {
    this->attack = attack;
}

int Enemy::getDefense() const {
    return this->defense;
}

int Enemy::getHP() const {
    return this->hp;
}

std::string Enemy::getName() const {
    return this->name;
}

std::string Enemy::getSpriteFile() const {
    return this->spriteFile;
}

void Enemy::setDefense(int defense) {
    this->defense = defense;
}

void Enemy::setHP(int hp) {
    this->hp = hp;
}

void Enemy::setName(std::string name) {
    this->name = name;
}

void Enemy::setCounter(int counter) {
    this->counter = counter;
}

