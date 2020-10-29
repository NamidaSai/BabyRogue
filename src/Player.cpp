#include "Player.h"

#include <iostream>
#include <random>
#include <ctime>

Player::Player()
{
    x_ = 1;
    y_ = 1;
    sprite_ = '@';
}


/*************************** PUBLIC FUNCTIONS ***************************/


void Player::Spawn(Level level)
{
    for (int y = 0; y < level.GetHeight(); ++y)
    {
        for (int x = 0; x < level.GetWidth(); ++x)
        {
            if (level.GetTile(x,y) == '@')
            {
                SetPosition(x, y);
                return;
            }
            else
            {
                continue;
            }
        }
    }
    
    std::cout << "Level's player start position not found.\n";
}

void Player::HandleInput(char input, Level& level)
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
        level.SetTile(x_, y_, sprite_);
    }
    else
    {
        std::cout << "Can't move there!\n";
        system("PAUSE");
    }
}


/*************************** PRIVATE FUNCTIONS ***************************/


bool Player::CanMoveTo(int x, int y, Level& level)
{
    switch (level.GetTile(x, y))
    {
        case '#':               // wall
            return false;
        case '.':               // empty
            return true;
        case '$':               // shop
            return true;
        case 'X':               // treasure
            return true;
        case 'Y':               // exit
            level.NextLevel(true);
            return true;
        case 'Z':
            level.PrevLevel(true);
            return true;
        default:                // monster
            Attack(level.GetMonster(x, y));
            return false;
    }
}

void Player::Attack(Monster monster)
{
    mt19937 randomGenerator(time(0));
    uniform_real_distribution<int> attackRoll(1, 20);

    int playerAttack = attackRoll(randomGenerator) + attack_;
    int monsterAttack = attackRoll(randomGenerator) + monster.GetAttack();
    int combatResult = playerAttack - monsterAttack;

    if (combatResult > 0)
    {
        monster.TakeDamage(combatResult);
    }
    else if (combatResult == 0)
    {
        // send message "The player and monster hold each other in check!"
    }
    else
    {
        TakeDamage(combatResult);
    }
}

void Player::TakeDamage(int amount)
{
    if (amount >= defense_)
    {
        damage = amount - defense_;
        health_ -= damage;
        // send message "The player took [damage] damage!"
    }
    else
    {
        // send message "The player's armor absorbed the blow!"
    }

    if (health_ <= 0)
    {
        // Game Over;
    }
}