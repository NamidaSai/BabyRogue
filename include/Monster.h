#ifndef MONSTER_H
#define MONSTER_H
#include <string>
using namespace std;

class Monster{
    public:
        Monster(string MonsterType);
        int attack;
        int defense;
        int health;
        string type;        
        tuple<int,int,int> getValues(string);
};

#endif