//
//  Game.cpp
//  DungeonGame
//
//  Created by Joshua Presley on 2022-11-02.
//
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "Game.hpp"
#include "Character.hpp"


Game::Game(){
    
}
Game::~Game(){
    
}

void Game::playGame(std::vector<Player> &party){
    //get number of levels
    int levels = std::rand() % 5 + 10;
    for(int i = 0; i<levels;i++){
        //create room
        Room currentRoom{this->getLevel()};
        currentRoom.createEnemies(this->getLevel());
        currentRoom.doCombat(party);
    }
    //
    //
}

int Game::getLevel(){
    return this->level;
}
void Game::upLevel(){
    this->level++;
}

void Room::createEnemies(int level){
    int numberOfMonsters = rand() % (level + 1) + 1;
    std::vector<Monster> Monsters;
    for(int i = 0; i <= numberOfMonsters; i++){
        Monster m{"Orc " + std::to_string(i)};
        Monsters.push_back(m);
    }
    this->enemies = Monsters;
}

Room::Room(int level){
    this->level = level;
}

void Room::doCombat(std::vector<Player> &party){
    //sort party and enemies by initiative value
    std::sort(party.begin(), party.end());
    std::sort(this->getEnemies().begin(), this->getEnemies().end());
    
    
    std::vector<Character*> turnOrder;
    turnOrder.reserve(party.size()+this->enemies.size());
    std::merge(party.begin(), party.end(), this->enemies.begin(), this->enemies.end(), std::back_inserter(turnOrder));
    
    //combat loop
    for(Character * currentCharacter : turnOrder){
        //is character player? else monster
        if(dynamic_cast<Player*>(currentCharacter) != nullptr){
            Player * current = dynamic_cast<Player *>(currentCharacter);
            current->attack(this->enemies);
        }
        else{
            Monster * current = dynamic_cast<Monster *>(currentCharacter);
            current->attack(party);
        }
        
        
    }
}

std::vector<Monster> Room::getEnemies(){
    return this->enemies;
}

Room::~Room(){
    
}
