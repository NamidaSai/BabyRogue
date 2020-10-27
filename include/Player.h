#ifndef PLAYER_H
#define PLAYER_H

#include "Level.h"

class Player
{
    public:
        Player();

        void HandleMovement(char input, Level& level);
        bool CanMoveTo(int x, int y, Level level);

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

};

#endif /* PLAYER_H */