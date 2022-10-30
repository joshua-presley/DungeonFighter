//
//  Character.hpp
//  DungeonGame
//
//  Created by Joshua Presley on 2022-10-30.
//

#ifndef Character_hpp
#define Character_hpp

#include <iostream>
class Character{
public:
    Character(std::string name, int level): name(name), level(level){}
    Character(std::string name): name(name), level(0){}
    
    std::string getName();
    int getLevel();
    
private:
    std::string name;
    int level;
};
class Player: public Character{
    
};

class Monster: public Character{
    
};

#endif /* Character_hpp */
