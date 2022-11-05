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
    Character(std::string name);
    
    std::string getName();
    int getLevel();
    int getInitiative();
    virtual void attack(Character characterToAttack);
    friend bool operator<(const Character& lhs, const Character& rhs);
    
protected:
    std::string name;
    int level{};
    int healthpoints{};
    int armour{};
    int initiative{rand() % 19 + 1};
    //stats
    int strength{};
    int agility{};
    int constitution{};
    int intelligence{};
    int wisdom{};
};
class Player: public Character{
public:
    Player(std::string name): Character(name){}
};

class Monster: public Character{
public:
    Monster(std::string type): Character(type){}
};


#endif /* Character_hpp */
