#include "Player.h"

#include <iostream>

Player::Player()
{

}

void Player::Update(Level &level)
{
    std::cout << "Player was updated.\n";
    level.SetTile(GetX(), GetY(), sprite_);
}