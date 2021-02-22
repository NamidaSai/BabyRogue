#ifndef SHOP_H
#define SHOP_H
#include "Item.h"
#include <vector>
#include <string>

using namespace std;

class Shop {
    public:
    Shop(vector<string> shopNames);
    vector<int> SetShopItems(int minItems, int maxItems, vector<Item> allItems);
    vector<Item> GetShopItems() {return shopItems;}
    string GetShopName() {return shopName;}
    int GetShopMoney() {return money;}
    tuple<bool, string> ValidatePlayerPurchase(int playerChoice, int playerMoney);
    tuple<string, Item> PlayerBuysItem(int playerChoice); 
    void PlayerSellsItem(Item soldItem);
    bool DoesShopHaveItems();
    
    private:
    vector<Item> shopItems;
    string shopName;
    int money;
    void SetShopNameAndMoney(vector<string> shopNames);    
};

#endif