#ifndef MONSTER_H
#define MONSTER_H
#include <string>
using namespace std;

class Monster{
    public:
        Monster(string monsterType);
        int GetAttack() { return attack; }
        int GetDefense() { return defense; }
        int GetHealth() { return health; }
        string GetType() { return type; }
    private:
        int attack;
        int defense;
        int health;
        string type;        
        void SetValues(string);
};

#endif /*MONSTHER_H*/