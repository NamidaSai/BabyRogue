#ifndef SHOP_H
#define SHOP_H
#include <vector>
#include <string>
#include "Item.h"
using namespace std;

class Shop {
    public:
    Shop(vector<string> shopNames);
    
    vector<int> SetShopItems(int minItems, int maxItems, vector<Item> allItems);
    tuple<string, Item> PlayerBuysItem(int playerChoice, int playerMoney); //This returns to the main function saying if purchase was success or not
    void PlayerSellsItem(Item soldItem);
    tuple<bool, string> ValidatePlayerPurchase(int playerChoice, int playerMoney);
    
    string GetShopName() {return shopName;}
    int GetShopMoney() {return money;}
    vector<Item> GetShopItems() {return shopItems;}
    bool DoesShopHaveItems();
    
    private:
    vector<Item> shopItems;
    string shopName;
    int money;
    //functional functions
    void SetShopNameAndMoney(vector<string> shopNames);
    
};

#endif