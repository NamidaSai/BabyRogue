#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H
#include "Item.h"
#include <string>
#include <vector>

using namespace std;

class ItemManager {
    public:
    ItemManager();
    vector<Item> GetItems() {return shop;}
    vector<Item> GetAllShopItems() {return allShopItems;}
    vector<Item> GetRemainingShopItems() {return remainingShopItems;}
    void UpdateRemainingItems(vector<int> eraseItems);
    
    private:
    int GetMaxItems();
    void GetAllShopItemsFromItem();
    vector<Item> shop;
    vector<int> idArray;
    vector<Item> allShopItems;
    vector<Item> remainingShopItems;
};

#endif