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
    std::vector<Monster> * getEnemies();
    void createEnemies(int level);
    void enterRoom();
    void doCombat(std::vector<Player> &party);
    void endCombat();
    auto getNext(std::vector<Player> * party, std::vector<Monster>, int lastInitiative);

    //std::vector<loot>
    ~Room();
    
private:
    std::vector<Monster> enemies;
    bool cleared{false};
    int level;
};


class Game{
    //main game controller class
    
public:
    Game();
    Room createRoom(); //create a room
    int getLevel();
    void upLevel();
    void playGame(std::vector<Player> &party);
    ~Game();
    
private:
    int level{0};
    
};


#endif /* Game_hpp */

