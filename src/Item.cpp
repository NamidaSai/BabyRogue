//first we will need to extract the total number of items and then use a random function to pick one of the items.
#include <iostream>
#include <fstream>
#include <regex>
#include "Item.h"

using namespace std;

Item::Item(){
    cout<<"Function called"<<endl;
    SetValues();
}

void Item::SetValues(){
    string text;
    ifstream file("Data/item.json");
    
    cout<<"function called"<<endl;

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
        //count the number of "
        for (int i = 0; i < n; i++){
            if (carray[i] == '"'){
                totalQuotes += 1;
            }
        }

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
    }
}