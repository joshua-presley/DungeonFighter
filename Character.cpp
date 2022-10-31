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
    return this->name;
}
int Character::getLevel(){
    return this->level;
}

void Character::attack(Character *characterToAttack){
    //check if hit
    srand(time(NULL));
    int roll = rand() % 20;
    std::cout << getName() << " is attacking " << characterToAttack->getName() << "\n";
    std::cout << "Attack roll: " << roll << "\n";
    if(roll > characterToAttack->armour){
        std::cout << "Hit!\n";
    }
    else{
        std::cout << "Miss!";
    }
}
