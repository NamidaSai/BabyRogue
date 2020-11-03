#include <iostream>
#include <fstream>
#include "Monster.h"
#include <regex>

using namespace std;

Monster::Monster(char monsterSprite){
    SetValues(monsterSprite);
}

void Monster::SetValues(char choice){
    string myText;
    ifstream myFile("Data/monsters.json");
    bool found = false;
    string closedbracket = "}";
    
    while(getline(myFile, myText)){
        int n = myText.length();
        char carray[n+1];
        int pos1 = 0;
        int wordLength = 0;
        int wordend = 0;
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
                    break;
                }                
            }

        }
        wordend = pos1 + wordLength;
        for (int i = pos1+1; i <= wordend; i++){
            word = word + carray[i];
        }
        
        if (word == "Sprite"){
            for (int i = wordend + 2; i < strlen(carray); ++i){
                if (carray[i] == '"'){
                    sprite = carray[i+1]; //since our sprite is always one letter char its possible to do without finding length of sprite
                    if (sprite == choice){
                        found = true;
                        break;
                    }
                }
            }
        }
        else if (word == "Health"){
            health = stoi(finalval);
        }
        else if (word == "Defense"){
            defense = stoi(finalval);
        }
        else if (word == "Attack"){
            attack = stoi(finalval);
        }
        else if (wordLength > 0){
            type = word;
        }
        else if (strstr(myText.c_str(), closedbracket.c_str()) && found == true){
            break;
        }
    }
    try {
        if (found == false){
            throw "Incorrect monster name";
        }
    }catch (const char* msg){
        cout<<msg<<endl;
        exit(0); 
    }
    
}