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
    int levels = rand() % 5 + 10; //todo change this back to rand from 10 to 15
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

auto Room::getNext(std::vector<Player> *party, std::vector<Monster>, int lastInitiative){
    return party[0];
}

void Room::doCombat(std::vector<Player> &party){
    std::cout << "new combat\n";
    //sort party and enemies by initiative value
    std::vector<Monster> * enemies = this->getEnemies();
    //sort both lists for turn order
    std::sort(party.begin(), party.end());
    std::sort(enemies->begin(), enemies->end());
    
    int nextPlayerIndex{0};
    int nextMonsterIndex{0};
    //temporary
    int rounds = (int)(party.size() + enemies->size());
    
    //start last initiative at 21 so getNext will choose highestInit character
    //int lastInitiative{21};
    
    for(int i = 0; i<rounds; i++){
        //grab next characters from both lists
        Player * nextPlayer;
        Monster * nextMonster;
        
        //select next player/monster
        //todo: figure out if char has acted this round
        try{
            nextPlayer = &(party.at(nextPlayerIndex));
        }
        catch(std::out_of_range e){
            nextPlayerIndex = 0; //have reached the end of player list
            nextPlayer = &(party.at(nextPlayerIndex));
        }
        try{
            nextMonster = &(enemies->at(nextMonsterIndex));
        }
        catch(std::out_of_range e){
            nextMonsterIndex = 0;
            nextMonster = &(enemies->at(nextMonsterIndex));
        }
        
        
        
        //this if statement seems backwards. operator is reversed
        if(*nextPlayer < *nextMonster){
            nextPlayer->attack();
            nextPlayerIndex++;
        }
        else{
            nextMonster->attack();
            nextMonsterIndex++;
        }
    }
}



std::vector<Monster> * Room::getEnemies(){
    return &(this->enemies);
}

Room::~Room(){
    
}
