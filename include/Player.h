#ifndef PLAYER_H
#define PLAYER_H
#include "Item.h"
#include "Level.h"
#include <vector>
#include <tuple>

class Player
{
    public:
        Player();

        void Spawn(Level level);
        void HandleInput(char input, Level& level);

        int GetX() { return x_; }
        int GetY() { return y_; }
        char GetSprite() { return sprite_; }

        void SetPosition(int x, int y)
        {
            x_ = x;
            y_ = y;
        }
        void HandleBoughtItem(Item boughtItem);
        tuple<string, Item> SellItem(int playerChoice, int shopMoney);
        tuple<bool, string> ValidatePlayerSales(int playerChoice, int shopMoney);
        vector<Item> GetPlayerItems() { return playerItems; }
        bool DoesPlayerHaveItems();
        int GetMoney() { return money; }//money var should be set during spawn

    private:
        int x_, y_;
        char sprite_;
        int money = 1000;
        vector<Item> playerItems;
        bool CanMoveTo(int x, int y, Level& level);
};

#endif /* PLAYER_H */