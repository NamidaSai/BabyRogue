#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    public:
        Player()
        : x_(0), y_(0), sprite_('@') {}

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