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

class Game{
    //main game controller class
    
public:
    Game();
    void createRoom(); //create a room
    void enterRoom();
    void doCombat();
    void endCombat();
    void getLevel();
    void upLevel();
    void playGame(std::vector<Player> &party);
    ~Game();
    
private:
    int level{0};
    
};

//room is entered by players and contains enemies and items
class Room{
public:
    Room(int level);
    std::vector<Character> getEnemies();
    std::vector<Character> createEnemies();
    //std::vector<loot>
    ~Room();
    
};

#endif /* Game_hpp */

