//
//  Game.cpp
//  DungeonGame
//
//  Created by Joshua Presley on 2022-11-02.
//
#include <vector>
#include <cstdlib>
#include "Game.hpp"
#include "Character.hpp"

void Game::playGame(std::vector<Player> &party){
    //get number of levels
    int levels = std::rand() % 15 + 10;
    for(int i = 0; i<levels;i++){
        //create room
        Room currentRoom{this->getLevel()};
        currentRoom.createEnemies(this->getLevel());
        currentRoom.doCombat();
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
    int numberOfMonsters = rand() % level + 1;
    std::vector<Monster> Monsters;
    for(int i = 0; i < numberOfMonsters; i++){
        Monster m{"Orc " + std::to_string(i)};
        Monsters.push_back(m);
    }
    this->
}

