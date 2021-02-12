#ifndef SHOP_H
#define SHOP_H
#include <vector>
#include <string>
#include "Item.h"
using namespace std;

class Shop {
    public:
    Shop(vector<string> shopNames);
    string GetShopName() {return shopName;}
    int GetShopMoney() {return money;}
    vector<Item> GetShopItems() {return shopItems;}
    vector<int> SetShopItems(int minItems, int maxItems, vector<Item> allItems);
    private:
    void SetShopNameAndMoney(vector<string> shopNames);
    vector<Item> shopItems;
    string shopName;
    int money;
};

#endif