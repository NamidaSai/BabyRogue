#include <iostream>
#include <fstream>
#include "Monster.h"
#include <regex>

using namespace std;
//TODO: monstertype does not exist in JSON
//TODO: change monstertype from troll to T and goblin to G

Monster::Monster(string monsterType){
    SetValues(monsterType);
}

void Monster::SetValues(string choice){
    string myText;
    ifstream myFile("Data/monsters.json");
    bool found = false;
    string closedbracket = "}";
    
    while(getline(myFile, myText)){
        int n = myText.length();
        char carray[n+1];
        int pos1;
        int wordLength;
        int wordend;
        string word;
        bool flag = false;
        string value;
        string finalval;

        finalval = regex_replace(
            myText,
            regex("[^0-9]*([0-9]+).*"),
            string("$1")
        );
        
        strcpy(carray, myText.c_str());
        for (int i = 0; i < n; i++){
            if (carray[i] == '"'){
                if(flag == false){
                    pos1 = i;
                    flag = true;
                }
                else{
                    wordLength = i - pos1 - 1;
                    flag = false;
                }                
            }

        }
        wordend = pos1 + wordLength;
        for (int i = pos1+1; i <= wordend; i++){
            word = word + carray[i];
        }
        if(!found){
            if (word == choice){
                found = true;
            }
        }
        else if(found){
            if (word == "Health"){
                health = stoi(finalval);
            }
            else if (word == "Defense"){
                defense = stoi(finalval);
            }
            else if (word == "Attack"){
                attack = stoi(finalval);
            }
            else if (strstr(myText.c_str(), closedbracket.c_str())){
                break;
            }
        }
    }
    type = choice;
}