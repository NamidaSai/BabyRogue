#ifndef MONSTER_H
#define MONSTER_H
#include <string>
using namespace std;

class Monster{
    public:
        Monster(char monsterSprite);
        int GetAttack() { return attack_; }
        int GetDefense() { return defense_; }
        int GetHealth() { return health_; }
        string GetType() { return type; }
        char GetSprite() { return sprite_; }
        void SetPosition (int x, int y) { x_ = x; y_ = y;} 
        int GetX() { return x_; }
        int GetY() { return y_; }
        void TakeDamage(int value);
    private:
        int x_,y_;
        char sprite_;
        int attack_ = 0;
        int defense_ = 0;
        int health_ = 0;
        string type;        
        void SetValues(char);
};

#endif /*MONSTHER_H*/