//
//  Character.cpp
//  DungeonGame
//
//  Created by Joshua Presley on 2022-10-30.
//
#include <iostream>
#include <time.h>
#include "Character.hpp"

Character::Character(std::string name){
    this->name = name;
    armour = 10;
    level = 0;
}

std::string Character::getName(){
    return name;
}
int Character::getLevel(){
    return this->level;
}
int Character::getInitiative(){
    return this->initiative;
}
int Character::getArmour(){
    return this->armour;
}

void Player::attack(std::vector<Monster> & vectorOfTargets){
    //check if hit
    
    std::cout << this->name << ": Choose a target:\n";
    srand((unsigned int)time(NULL));
    int i=0;
    int characterChoice{};
    //int roll = rand() % 20;
    for(Monster mon: vectorOfTargets){
        std::cout<< i++ << ": " << mon.getName() << "\n";
    }
    std::cin >> characterChoice;
    int roll = rand() % 19 + 1;
    
    std::vector<Monster>::iterator targetMonster = vectorOfTargets.begin() + characterChoice;
    
    if(roll > targetMonster->getArmour()){
        std::cout << this->name << " attack roll: " << roll << " hit " << targetMonster->getName() << "\n\n\n";
        targetMonster->takeDamage(1); //todo: set this later
        if(targetMonster->isDead()){
            vectorOfTargets.erase(targetMonster);
        }
    }
    else{
        std::cout << this->name << " attack roll: " << roll << " miss " << targetMonster->getName() << "\n\n\n";
    }
    //increment in order to stop initiative problems in the turn order
    this->turnsTaken++;
    
}

void Monster::attack(std::vector<Player> & vectorOfTargets){
    //randomely choose a player to attack
    int size = (int)vectorOfTargets.size();
    int characterChoice = rand() % size;
    
    //get reference to player
    std::vector<Player>::iterator playerAttack = vectorOfTargets.begin() + characterChoice;
    //attack roll
    int roll = rand() % 19 + 1;
    if(roll > playerAttack->getArmour()){
        std::cout << this->name << " attack roll: " << roll << " hit " << playerAttack->getName() << " Armour: " << playerAttack->getArmour() << "\n\n\n";
        playerAttack->takeDamage(1);
        if(playerAttack->isDead()){
            vectorOfTargets.erase(playerAttack);
        }
    }
    else{
        std::cout << this->name << " attack roll: " << roll << " miss " << playerAttack->getName() << " Armour: " << playerAttack->getArmour() << "\n\n\n";
    }
    //increment this to stop problems with the turn order.
    this->turnsTaken++;
}


bool operator<(const Character& lhs, const Character& rhs){
        return lhs.initiative > rhs.initiative;
}

void Character::attack(){
    std::cout << "base class attack\n";
}

void Character::takeDamage(int damage){
    this->healthpoints -= damage;
}

bool Character::isDead(){
    return this->healthpoints <= 0;
}

int Character::getHealth(){
    return this->healthpoints;
}

int Character::getTurnsTaken(){
    return this->turnsTaken;
}
