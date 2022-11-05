//
//  main.cpp
//  DungeonGame
//
//  Created by Joshua Presley on 2022-10-30.
//
#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Game.hpp"
#include <time.h>

//get a number of players
std::vector<Player> getPlayers(int size){
    
    std::vector<Player> ret;
     
    for(int i=0;i<size;i++){
        std::string name;
        std::cout<<"Enter name of character " << i + 1 << ": ";
        std::cin >> name;
        Player pl{name};
        ret.push_back(pl);
    }
    
    return ret;
}


int main(int argc, const char * argv[]) {
    srand((unsigned int)time(NULL));
    //enter players
    int size{};
    std::cout << "Enter party size: ";
    std::cin >> size;
    std::vector<Player> players;
    players = getPlayers(size);
    std::cout << players[0].getName() << " initiative: " << players[0].getInitiative() <<"\n";
    std::cout << players[1].getName() << " initiative: " << players[1].getInitiative() <<"\n";
    std::cout << (players[0] < players[1]);
    //initialize game
    Game game;
    game.playGame(&players);
    
    return 0;
}
