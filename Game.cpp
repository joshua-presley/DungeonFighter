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

Game::Game(){
    
}
Game::~Game(){
    
}

void Game::playGame(std::vector<Player> * party){
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

void Room::doCombat(std::vector<Player> * party){
    //get initiative
    std::vector<Character> turnOrder;
    
    //combat loop
}

Room::~Room(){
    
}
