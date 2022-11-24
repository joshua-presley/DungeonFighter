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
#include "Utilities.hpp"

//get a number of players
std::vector<Player> getPlayers(int size){
    
    std::vector<Player> ret;
     
    for(int i=0;i<size;i++){
        std::string name;
        name = getStringChoice(("Enter name of character " + std::to_string(i + 1) + ": "));
        Player pl{name};
        pl.takeDamage(-5);
        ret.push_back(pl);
    }
    
    return ret;
}


int main(int argc, const char * argv[]) {
    srand((unsigned int)time(NULL));
    //enter players
    int size{};
    size = getIntChoice(1, 4, "Enter number of players (1 to 4): ");
    std::vector<Player> players;
    players = getPlayers(size);
    //initialize game
    Game game;
    game.playGame(players);
    
    return 0;
}
