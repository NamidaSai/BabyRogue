#ifndef MONSTER_H
#define MONSTER_H
#include <string>
using namespace std;

class Monster{
    public:
        Monster(char monsterSprite);
        int GetAttack() { return attack; }
        int GetDefense() { return defense; }
        int GetHealth() { return health; }
        string GetType() { return type; }
        char GetSprite() { return sprite; }
        void SetPosition (int x, int y) { x_ = x; y_ = y;} 
        int GetX() { return x_; }
        int GetY() { return y_; }
    private:
        int x_,y_;
        char sprite;
        int attack = 0;
        int defense = 0;
        int health = 0;
        string type;        
        void SetValues(char);
};

#endif /*MONSTHER_H*/