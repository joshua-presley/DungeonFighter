//
//  Character.hpp
//  DungeonGame
//
//  Created by Joshua Presley on 2022-10-30.
//

#ifndef Character_hpp
#define Character_hpp

#include <iostream>
#include <vector>

class Monster;


class Character{
public:
    Character(std::string name, int level): name(name), level(level){}
    Character(std::string name);
    
    std::string getName();
    int getLevel();
    int getInitiative();
    int getArmour();
    virtual void attack(std::vector<Monster> &vectorOfTargets);
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
    void attack(std::vector<Monster> &vectorOfTargets);
};

class Monster: public Character{
public:
    Monster(std::string type): Character(type){}
    void attack(std::vector<Player> &vectorOfTargets);
};


#endif /* Character_hpp */
