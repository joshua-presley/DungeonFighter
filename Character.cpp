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

void Player::attack(std::vector<Monster> &vectorOfTargets){
    //check if hit
    std::cout << "Choose a target:\n";
    srand((unsigned int)time(NULL));
    int i=0;
    int characterChoice{};
    //int roll = rand() % 20;
    for(Monster mon: vectorOfTargets){
        std::cout<< i++ << ": " << mon.getName() << "\n";
    }
    std::cin >> characterChoice;
    int roll = rand() % 19 + 1;
    
    if(roll > vectorOfTargets[characterChoice].getArmour()){
        std::cout << this->name << " hit " <<vectorOfTargets[characterChoice].getName() << "\n";
    }
    else{
        std::cout << this->name << " miss " <<vectorOfTargets[characterChoice].getName() << "\n";
    }
    
}

void Monster::attack(std::vector<Player> &vectorOfTargets){
    //choose player to attack
    int size = (int)vectorOfTargets.size();
    srand((unsigned int)time(NULL));
    int characterChoice = rand() % size;
    
    //attack roll
    int roll = rand() % 19 + 1;
    if(roll > vectorOfTargets[characterChoice].getArmour()){
        std::cout << this->name << " hit " <<vectorOfTargets[characterChoice].getName() << "\n";
    }
    else{
        std::cout << this->name << " miss " <<vectorOfTargets[characterChoice].getName() << "\n";
    }
}

bool operator<(const Character& lhs, const Character& rhs){
    return lhs.initiative < rhs.initiative;
}
