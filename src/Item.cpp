//first we will need to extract the total number of items and then use a random function to pick one of the items.
#include <iostream>
#include <fstream>
#include <regex>
#include "Item.h"

using namespace std;

Item::Item(){
    SetValues();
}

void Item::SetValues(){
    string text;
    ifstream file("Data/item.json");
    
}