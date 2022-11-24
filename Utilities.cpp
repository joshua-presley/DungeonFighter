//
//  Utilities.cpp
//  DungeonGame
//
//  Created by Joshua Presley on 2022-11-22.
//

#include "Utilities.hpp"

int getIntChoice(int rangeLow, int rangeHigh, std::string message){
    while (true){
        std::cout << message;
        int choice{};
        std::cin >> choice;
        if(!std::cin){
            std::cin.clear();
            ignoreLine();
            std::cerr << "invalid choice\n";
        }
        else{
            if(choice >= rangeLow && choice <= rangeHigh){
                ignoreLine();
                return choice;
            }
            else{
                std::cerr << "invalid choice\n";
            }
        }
    }
    return 0;
}


std::string getStringChoice(std::string message){
    while (true){
        std::cout << message;
        std::string input{};
        if(!std::cin){
            std::cin.clear();
            ignoreLine();
            std::cerr << "invalid choice\n";
        }
        else{
            return message;
        }
    }
}

void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
