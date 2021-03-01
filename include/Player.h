#ifndef PLAYER_H
#define PLAYER_H
#include "Item.h"
#include "Level.h"
#include "Monster.h"
#include <vector>
#include <tuple>

class Player
{
    public:
        Player();
        void Spawn(Level level);
        void HandleInput(char input, Level& level);
        void AddMoney(int amount);
        void RemoveMoney(int amount);

        int GetX() { return x_; }
        int GetY() { return y_; }
        char GetSprite() { return sprite_; }
        void SetPosition(int x, int y)
        {
            x_ = x;
            y_ = y;
        }
        void HandleBoughtItem(Item boughtItem);
        tuple<string, Item> SellItem(int playerChoice);
        tuple<bool, string> ValidatePlayerSales(int playerChoice, int shopMoney);
        bool DoesPlayerHaveItems();
        vector<Item> GetPlayerItems() { return playerItems; }
        int GetMoney() { return money; }

    private:
        int x_, y_;
        char sprite_;
        vector<Item> playerItems;
        int health_ = 20;
        int attack_ = 5;
        int defense_ = 2;
        int money_ = 1000;

        bool CanMoveTo(int x, int y, Level& level);
        void Attack(Monster& monster);
        void TakeDamage(int amount);
};

#endif /* PLAYER_H */