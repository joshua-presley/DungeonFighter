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
        
        if(party.size() > 0){
            //create room
            Room currentRoom{this->getLevel()};
            currentRoom.createEnemies(this->getLevel());
            //reset turncount
            
            for(std::vector<Player>::iterator it = party.begin(); it < party.end(); it++){
                (*it).resetTurnCount();
            }
            
            currentRoom.doCombat(party);
        }
        else{
            std::cout << "The party has died. You survived " << i << " levels.\n";
            break;
        }
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
    std::vector<Monster> * enemies = this->getEnemies();
    //sort both lists for turn order
    std::sort(party.begin(), party.end());
    std::sort(enemies->begin(), enemies->end());
    
    
    //int nextPlayerIndex{0};
    //int nextMonsterIndex{0};
    
    //bool havePlayer{false};
    //bool haveMonster{false};
    int i = 1;
    std::vector<Player>::iterator nextPlayer = party.begin();// = nullptr;
    std::vector<Monster>::iterator nextMonster = enemies->begin();// = nullptr;
    while(party.size() > 0 && enemies->size() > 0){
        //remove dead characters here
        //if doing it in the attack method it messes up the iterator
        if(nextPlayer->isDead()){
            party.erase(nextPlayer++);
            //make sure we don't go past the end
            if(party.size() == 0){
                break;
            }
            else if(nextPlayer == party.end()){
                nextPlayer = party.begin();
            }
        }
        if(nextMonster->isDead()){
            enemies->erase(nextMonster++);
            //make sure we haven't gone past the end
            if(enemies->size() == 0){
                break;
            }
            else if(nextMonster == enemies->end()){
                nextMonster = enemies->begin();
            }
        }
        printRoom(&party, enemies, i++);
        
        //this if statement seems backwards. operator< is reversed to sort turn order properly
        if(nextPlayer->getTurnsTaken() == nextMonster->getTurnsTaken()){
            if(*nextPlayer < *nextMonster){
                nextPlayer->attack(*enemies);
                if(std::next(nextPlayer) == party.end()){
                    nextPlayer = party.begin();
                }
                else{
                    nextPlayer++;
                }
            }
            else{
                nextMonster->attack(party);
                if(std::next(nextMonster) == enemies->end()){
                    nextMonster = enemies->begin();
                }
                else{
                    nextMonster++;
                }
                
            }
        }
        else if (nextPlayer->getTurnsTaken() < nextMonster->getTurnsTaken()){
            nextPlayer->attack(*enemies);
            if(std::next(nextPlayer) == party.end()){
                nextPlayer = party.begin();
            }
            else{
                nextPlayer++;
            }
        }
        else{
            nextMonster->attack(party);
            if(std::next(nextMonster) == enemies->end()){
                nextMonster = enemies->begin();
            }
            else{
                nextMonster++;
            }
        }
        
    }
}

void Room::printRoom(std::vector<Player> * players, std::vector<Monster> * monsters, int level){
    std::vector<Player>::iterator itPlayer;
    std::vector<Monster>::iterator itMonster;
    std::cout << "**************** Round " << level << " ****************\n";
    
    for(itMonster = monsters->begin(); itMonster < monsters->end(); itMonster++){
        std::cout << itMonster->getName() << "    ";
    }
    std::cout << "\n";
    for(itMonster = monsters->begin(); itMonster < monsters->end(); itMonster++){
        std::cout << itMonster->getHealth() << "         ";
    }
    
    
    std::cout << "\n\n";
    for(itPlayer = players->begin(); itPlayer < players->end(); itPlayer++){
        std::cout << itPlayer->getName() << "    ";
    }
    std::cout << "\n";
    for(itPlayer = players->begin(); itPlayer < players->end(); itPlayer++){
        std::cout << itPlayer->getHealth() << "    ";
    }
    std::cout << "\n******************************************\n";
    
    
    
}

std::vector<Monster> * Room::getEnemies(){
    return &(this->enemies);
}

Room::~Room(){
    
}
