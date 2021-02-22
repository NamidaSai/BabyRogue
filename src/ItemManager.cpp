#include "ItemManager.h"
#include "Item.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <regex>
#include <vector>

using namespace std;

ItemManager::ItemManager(){
    GetAllShopItemsFromItem();
}

int ItemManager::GetMaxItems(){
    int maxID = 0;
    string text;
    bool found = false;
    ifstream file("Data/item.json");
    string openBracket = "{";
    string closedBracket = "}";

    while(getline(file,text)){
        int n = text.length();
        int totalQuotes = 0;
        char carray[n+1];
        int pos1 = 0;
        int wordLength = 0;
        int wordEnd = 0;
        string word;
        string num;
        bool flag = false;

        num = regex_replace(
            text,
            regex("[^0-9]*([0-9]+).*"),
            string("$1")
        );

        strcpy(carray, text.c_str());

        for (int i = 0; i < n; i++){
            if (carray[i] == '"'){
                if (flag == false){
                    pos1 = i;
                    flag = true;
                }
                else {
                    wordLength = i - pos1 - 1;
                    flag = false;
                    break;
                }
            }
        }
        wordEnd = pos1 + wordLength;
        for (int i = pos1 + 1; i <= wordEnd; i++){
            word = word + carray[i];
        }
        if (word == "id"){
            maxID = stoi(num);
        }
    }
    return maxID;
}

void ItemManager::GetAllShopItemsFromItem(){
    const int maxItems = GetMaxItems();
    for (int i = 1; i <= maxItems; i++){
        Item item;
        item.SetValues(i);
        allShopItems.push_back(item);
    }
    remainingShopItems = allShopItems;
}

void ItemManager::UpdateRemainingItems(vector<int> eraseItems){
    vector<Item> temp;
    for (int i = 0; i < remainingShopItems.size(); i++){
        if (find(begin(eraseItems), end(eraseItems), i) == end(eraseItems)){
            temp.push_back(remainingShopItems[i]);
        }
    }
    remainingShopItems = temp;
}