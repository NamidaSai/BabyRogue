#include "Player.h"

#include <iostream>

Player::Player()
{
    x_ = 1;
    y_ = 1;
    sprite_ = '@';
}

void Player::HandleMovement(char input, Level& level)
{
    int x = GetX();
    int y = GetY();

    int targetX = x;
    int targetY = y;

    switch (input)
    {
        case 'w':
            targetY = y - 1;
            break;
        case 's':
            targetY = y + 1;
            break;
        case 'a':
            targetX = x - 1;
            break;
        case 'd':
            targetX = x + 1;
            break;
        default:
            break;
    }

    if (CanMoveTo(targetX, targetY, level))
    {
        level.ResetTile(x, y);
        SetPosition(targetX, targetY);
        level.SetTile(GetX(), GetY(), GetSprite());
    }
    else
    {
        std::cout << "Can't move there!\n";
    }
}

bool Player::CanMoveTo(int x, int y, Level level)
{
    switch (level.GetTile(x, y))
    {
        case '.':
            return true;
        case '#':
            return false;
        default:
            return false;
    }
}