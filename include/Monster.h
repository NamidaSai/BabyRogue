#ifndef MONSTER_H
#define MONSTER_H
#include <string>
using namespace std;

class Monster{
    public:
        Monster(string monsterType);
        int attack;
        int defense;
        int health;
        string type;        
        tuple<int,int,int> GetValues(string);
};

#endif /*MONSTHER_H*/