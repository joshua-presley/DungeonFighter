//
//  Game.hpp
//  DungeonGame
//
//  Created by Joshua Presley on 2022-11-02.
//

#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include "Character.hpp"

template<class T>
struct Node{
    T data;
    Node * next;
};

//room is entered by players and contains enemies and items
class Room{
public:
    Room(int level);
    std::vector<Monster> getEnemies();
    void createEnemies();
    //std::vector<loot>
    ~Room();
    
private:
    std::vector<Monster> enemies;
    bool cleared{false};
};


class Game{
    //main game controller class
    
public:
    Game();
    Room createRoom(); //create a room
    void enterRoom();
    void doCombat();
    void endCombat();
    int getLevel();
    void upLevel();
    void playGame(std::vector<Player> &party);
    ~Game();
    
private:
    int level{0};
    
};


#endif /* Game_hpp */

