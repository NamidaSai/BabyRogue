#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H
#include <string>
#include "Item.h"
#include <vector>
using namespace std;

class ItemManager {
    public:
    Item * getShopItems(int minItems, int maxNoItems);
    vector<Item> GetItems() {return shop;}
    private:
    int GetMaxItems();
    vector<Item> shop;
};

#endif