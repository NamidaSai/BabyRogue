#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <regex>
#include "ItemManager.h"
#include "Item.h"
#include <vector>

using namespace std;

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

Item * ItemManager::getShopItems(int minItems, int maxNoItems) {
    const int maxItems = GetMaxItems();
    // if (maxNoItems < maxItems){
    //     maxItems = maxNoItems;
    // }
    srand(time(NULL));
    const int randTotalItems = rand() % (maxNoItems - minItems + 1) + minItems;
    cout<<"Total Items are: "<<randTotalItems<<endl;
    Item shopItems[randTotalItems];
    bool isFull = false;
    bool isPresent = false;
    //int idArray[randTotalItems];
    vector<int> idArray;
    int i = 0;
    while(i < randTotalItems){
        int randID = rand() % (maxNoItems - minItems + 1) + minItems;
        cout<<"Random ID is: "<<randID<<endl;
        if (find(begin(idArray), end(idArray), randID) != end(idArray)){
            continue;
        }
        idArray.push_back(randID);
        shopItems[i].SetValues(randID);
        shop.push_back(shopItems[i]);
        cout<<"Defense: "<<shopItems[i].GetDefense()<<endl;
        i = i + 1;
    }
    
    return shopItems;
}
