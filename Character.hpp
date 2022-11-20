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
    int getHealth();
    int getTurnsTaken();
    
    void takeDamage(int damage);
    bool isDead();
    virtual void attack();
    
    friend bool operator<(const Character& lhs, const Character& rhs);
    
protected:
    std::string name;
    int level{1};
    int healthpoints{2*level};
    int armour{};
    int initiative{rand() % 19 + 1};
    //stats
    int strength{};
    int agility{};
    int constitution{};
    int intelligence{};
    int wisdom{};
    int turnsTaken{}; //used to stop problems with only initiative in turn order.
    
};
class Player: public Character{
public:
    Player(std::string name): Character(name){}
    void attack(std::vector<Monster> & vectorOfTargets);
};

class Monster: public Character{
public:
    Monster(std::string type): Character(type){}
    void attack(std::vector<Player> & vectorOfTargets);
};


#endif /* Character_hpp */
