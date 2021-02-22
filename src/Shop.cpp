#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <regex>
#include "Item.h"
#include "Shop.h"
#include "JsonParser.h"
using namespace std;

Shop::Shop(vector<string> shopNames){
    SetShopNameAndMoney(shopNames);
}

vector<int> Shop::SetShopItems(int minItems, int maxItems, vector<Item> allItems){
    vector<int> selectedItems;
    if (minItems > maxItems){
        int temp = maxItems;
        maxItems = minItems;
        minItems = temp;
    }

    if (maxItems > allItems.size()){
        maxItems = allItems.size();
    }

    if (minItems > allItems.size()){
        minItems = allItems.size();
    }
    srand(time(NULL));
    const int randTotalItems = rand() % (maxItems - minItems + 1) + minItems;

    for (int i = 1; i <= randTotalItems; i++){
        const int randIndex = rand() % allItems.size();
        selectedItems.push_back(randIndex);
        shopItems.push_back(allItems[randIndex]);
        allItems.erase(allItems.begin() + randIndex);
    }

    return selectedItems;
}

void Shop::SetShopNameAndMoney(vector<string> shopNames){
    string text;
    bool found = false;
    ifstream file("Data/Shop.json");
    string openBracket = "{";
    string closedBracket = "}";

    while(getline(file,text)){
        int n = text.length();
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
        if (word == "Money"){
            money = stoi(num);
        }
        else if (wordLength > 0){
            for (auto& name : shopNames){
                if (name == word){
                    flag = true;
                }
            }
            if (flag == false){
                found = true;
            }
            shopName = word;
        }
        else if (strstr(text.c_str(), closedBracket.c_str()) && found == true){
            break;
        }
    }
    try {
        if (found == false){
            throw "All Shop Names have been used";
        }
    }catch (const char* msg){
        cout<<msg<<endl;
        exit(0);
    }
}

tuple<bool, string> Shop::ValidatePlayerPurchase(int playerChoice, int playerMoney){
    playerChoice -= 1;
    if (playerChoice < 0 || playerChoice > shopItems.size()-1){
        return {false, "Invalid Choice"};
    }

    if (shopItems[playerChoice].GetCost() > playerMoney){
        return {false, "Insuffecient Funds"};
    }

    return {true, "Approved"};
}

tuple<string, Item> Shop::PlayerBuysItem(int playerChoice){
    playerChoice -= 1;
    money += shopItems[playerChoice].GetCost();
    Item tempItem = shopItems[playerChoice];
    shopItems.erase(shopItems.begin() + playerChoice);
    string message = "Player Purchased "+shopItems[playerChoice].GetName();
    return {message, tempItem};
}

void Shop::PlayerSellsItem(Item soldItem){
    money -= soldItem.GetCost();
    shopItems.push_back(soldItem);
}

bool Shop::DoesShopHaveItems(){
    if (shopItems.empty()){
        return false;
    }
    else {
        return true;
    }
}