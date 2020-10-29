#ifndef PLAYER_H
#define PLAYER_H

#include "Level.h"
#include "Monster.h"

class Player
{
    public:
        Player();

        void Spawn(Level level);
        void HandleInput(char input, Level& level);
        void AddMoney(int amount);

        int GetX() { return x_; }
        int GetY() { return y_; }
        char GetSprite() { return sprite_; }

        void SetPosition(int x, int y)
        {
            x_ = x;
            y_ = y;
        }

    private:
        int x_, y_;
        char sprite_;

        int health_ = 20;
        int attack_ = 5;
        int defense_ = 2;

        int money_ = 0;

        bool CanMoveTo(int x, int y, Level& level);
        void Attack(Monster monster);
        void TakeDamage(int amount);
};

#endif /* PLAYER_H */