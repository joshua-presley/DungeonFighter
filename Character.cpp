//
//  Character.cpp
//  DungeonGame
//
//  Created by Joshua Presley on 2022-10-30.
//
#include <iostream>
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

void Character::attack(Character characterToAttack){
    //check if hit
    srand((unsigned int)time(NULL));
    int roll = rand() % 20;
    std::cout << this->getName() << " is attacking " << characterToAttack.getName() << "\n";
    std::cout << "Attack roll: " << roll << "\n";
    if(roll > characterToAttack.armour){
        std::cout << "Hit!\n";
    }
    else{
        std::cout << "Miss!";
    }
}

bool operator<(const Character& lhs, const Character& rhs){
    return std::tie(lhs.initiative) < std::tie(rhs.initiative);
}
