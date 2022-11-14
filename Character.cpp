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

void Player::attack(std::vector<Monster> * vectorOfTargets){
    //check if hit
    
    std::cout << "Choose a target:\n";
    srand((unsigned int)time(NULL));
    int i=0;
    int characterChoice{};
    //int roll = rand() % 20;
    for(Monster mon: *vectorOfTargets){
        std::cout<< i++ << ": " << mon.getName() << "\n";
    }
    std::cin >> characterChoice;
    int roll = rand() % 19 + 1;
    
    Monster * targetMonster = &(vectorOfTargets->at(characterChoice));
    
    if(roll > targetMonster->getArmour()){
        std::cout << this->name << " attack roll: " << roll << " hit " << targetMonster->getName() << "\n";
        targetMonster->takeDamage(1); //todo: set this later
    }
    else{
        std::cout << this->name << " attack roll: " << roll << " miss " << targetMonster->getName() << "\n";
    }
    //increment in order to stop initiative problems in the turn order
    this->turnsTaken++;
    
}

void Monster::attack(std::vector<Player> * vectorOfTargets){
    //randomely choose a player to attack
    int size = (int)vectorOfTargets->size();
    int characterChoice = rand() % size;
    
    //get reference to player
    Player * playerAttack = &(vectorOfTargets->at(characterChoice));
    //attack roll
    int roll = rand() % 19 + 1;
    if(roll > playerAttack->getArmour()){
        std::cout << this->name << " attack roll: " << roll << " hit " << playerAttack->getName() << " Armour: " << playerAttack->getArmour() << "\n";
        playerAttack->takeDamage(1);
    }
    else{
        std::cout << this->name << " attack roll: " << roll << " miss " << playerAttack->getName() << " Armour: " << playerAttack->getArmour() << "\n";
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
    if(this->healthpoints <= 0){
        this->die();
    }
}

void Character::die(){
    std::cout << this->name << " has died\n";
}

int Character::getHealth(){
    return this->healthpoints;
}

int Character::getTurnsTaken(){
    return this->turnsTaken;
}
