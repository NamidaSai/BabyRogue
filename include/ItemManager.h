#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H
#include <string>
#include "Item.h"
#include <vector>
using namespace std;

class ItemManager {
    public:
    ItemManager();
    Item * getShopItems(int minItems, int maxNoItems);
    vector<Item> GetItems() {return shop;}
    vector<Item> GetAllShopItems() {return allShopItems;}
    vector<Item> GetRemainingShopItems() {return remainingShopItems;}
    void UpdateRemainingItems(vector<int> eraseItems);
    
    private:
    int GetMaxItems();
    vector<Item> shop;
    vector<int> idArray;
    vector<Item> allShopItems;
    vector<Item> remainingShopItems;
    void GetAllShopItemsFromItem();
};

#endif