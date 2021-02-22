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
    //Handle the event when allItems is empty
    //Handle input checking if minItems are 0 or negative for example
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
    bool flag = false;
    ifstream file("Data/Shop.json");
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
/*This function will return a string to display on screen saying
    which item was bought or if there are insuffecient funds and then remove that item from inventory of shop
    after which the main function should reload the shopitems to display with the new money
    it will also return the amount of money to deduct from players money and which item to add to player inventory
    the main function will then pass those to the player function for updating the items and money
*/
tuple<string, Item*> Shop::PlayerBuysItem(int playerChoice, int playerMoney){
    //handle even when there are no items in shop
    playerChoice -= 1;
    if (playerChoice < 0){
        return {"Invalid Choice", NULL};
    }

    if (shopItems[playerChoice].GetCost() > playerMoney){
        return {"Insuffecient Funds", NULL};
    }

    money += shopItems[playerChoice].GetCost();
    shopItems.erase(shopItems.begin() + playerChoice);
    string message = "Player Purchased "+shopItems[playerChoice].GetName();
    return {message, &shopItems[playerChoice]};
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