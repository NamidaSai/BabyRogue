//first we will need to extract the total number of items and then use a random function to pick one of the items.
#include <iostream>
#include <fstream>
#include <regex>
#include "Item.h"

using namespace std;

// Item::Item(int choice){
//     SetValues(choice);
    
// }

void Item::SetValues(int choice){
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
        if (word == "Cost"){
            cost = stoi(num);
        }
        else if (word == "id"){
            if (choice == stoi(num)){
                found = true;
            }
        }
        else if (word == "Attack"){ 
            attack = stoi(num);
        }
        else if (word == "Defense"){
            defense = stoi(num);
        }
        else if (word == "Health"){
            health = stoi(num);
        }
        else if (word == "Consumable"){
            if (stoi(num) == 1){
                consumable = true;
            }
            else{
                consumable = false;
            }
        }
        else if (wordLength > 0){
            name = word;
        }
        else if (strstr(text.c_str(), closedBracket.c_str()) && found == true){
            break;
        }
    }
    try {
        if (found == false){
            throw "Incorrect Item ID provided";
        }
    }catch (const char* msg){
        cout<<msg<<endl;
        exit(0);
    }
}