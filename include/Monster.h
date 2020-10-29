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
        int SetPosition (int x, int y) { x_ = x; y_ = y;} 
    private:
        int x_,y_;
        int attack = 0;
        int defense = 0;
        int health = 0;
        string type;        
        void SetValues(string);
};

#endif /*MONSTHER_H*/