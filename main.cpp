//
//  main.cpp
//  DungeonGame
//
//  Created by Joshua Presley on 2022-10-30.
//

#include <iostream>
#include "Character.hpp"
//get a number of players
Player * getPlayers(int size){
    
    const int partySize{size};
    Player * players[partySize];
    
    for(int i=0;i<partySize;i++){
        std::string name;
        std::cout<<"Enter name of character " << i + 1 << ": ";
        std::cin >> name;
        Player pl = Player{name};
        *(players + i) = &pl;
    }
    
    return *players;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int size{};
    std::cout << "Enter party size: ";
    std::cin >> size;
    Player * players;
    players = getPlayers(size);
    //enter players

    //start game
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
