#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject
{
    public:
        Player();
        
        virtual void Update();

        char GetSprite() { return sprite_; }

    private:
        char sprite_ = '@';
};


#endif /* PLAYER_H */