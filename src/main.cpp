#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include "MainGame.h"
#include "ItemManager.h"
#include "Shop.h"
#include <algorithm>
#include "Item.h"
#include <vector>

using namespace std;

int * getRandom( ) {

   static int  r[10];

   // set the seed
   srand( (unsigned)time( NULL ) );
   
   for (int i = 0; i < 10; ++i) {
      r[i] = rand();
      cout << r[i] << endl;
   }

   return r;
}

int main()
{
    ItemManager myItems;
    vector<Shop> shops;
    vector<string> shopNames;
    //now we encounter a $
    string leveltile = "$";
    if (leveltile == "$"){
        for (auto& shop : shops){
            shopNames.push_back(shop.GetShopName());
        }
        Shop tempShop(shopNames);
        vector<int> eraseItems = tempShop.SetShopItems(1,2,myItems.GetRemainingShopItems());
        myItems.UpdateRemainingItems(eraseItems);
        shops.push_back(tempShop);
    }
    for (auto& shop : shops){
        cout<<"Shop name: "<<shop.GetShopName()<<endl;
        cout<<"shop money: "<<shop.GetShopMoney()<<endl;
        vector<Item> shopItems = shop.GetShopItems();
        cout<<"shop defense: "<<shopItems[0].GetDefense();
    }
    // ItemManager myItems;
    // vector<Item> shop = myItems.GetAllShopItems();
    // for (auto& shopItem : shop){
    //     cout<<"The defense is: "<<shopItem.GetDefense()<<endl;
    // }
    // shop.erase(shop.begin() + 1);
    // for (auto& shopItem : shop){
    //     cout<<"The defense is: "<<shopItem.GetDefense()<<endl;
    // }

    // ItemManager myItems;
    // myItems.getShopItems(1,2);
    // vector<Item> shop;
    // shop = myItems.GetItems();
    // for (auto& shopItem : shop){
    //     cout<<"The defense is: "<<shopItem.GetDefense()<<endl;
    // }
    // cout<<shop[0].GetDefense()<<endl;
    // cout<<"Next Item"<<endl;
    // vector<Item> shop2;
    // myItems.getShopItems(2,3);
    // shop2 = myItems.GetItems();
    // for(auto& shopItem2 : shop2){
    //     cout<<"The defense is: "<<shopItem2.GetDefense()<<endl;
    // }
    // srand(time(NULL));
    // int randitem = rand() % 5;
    // cout<<randitem<<endl;
    // randitem = rand() % 5;
    // cout<<randitem<<endl;
    // randitem = rand() % 5;
    // cout<<randitem<<endl;
    // randitem = rand() % 5;
    // cout<<randitem<<endl;
    // randitem = rand() % 5;
    // cout<<randitem<<endl;
    // a pointer to an int.
//    int *p;

//    p = getRandom();
   
//    for ( int i = 0; i < 10; i++ ) {
//       cout << "p[i]: " << i << ") : ";
//       cout << p[i] << endl;
//    }

   return 0;
    //ItemManager myItemManager;
    //cout<<myItemManager.GetMaxItems();
    // MainGame game;
    // game.RunGame();
    //Item myItem(3);
    //cout<<myItem.GetName()<<endl<<myItem.GetAttack()<<endl<<myItem.GetDefense()<<endl<<myItem.GetHealth()<<endl<<myItem.GetCost()<<endl;
    //cout<<myItem.GetConsumable()<<endl;
    //char carray[] = {'A','B', 'C'};
    //cout<<carray[-2];
    //system("PAUSE");  
    //return 0;
}

