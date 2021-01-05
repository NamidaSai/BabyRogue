#include <iostream>

#include "MainGame.h"
#include "Item.h"

int main()
{
    // MainGame game;
    // game.RunGame();
    Item myItem(3);
    cout<<myItem.GetName()<<endl<<myItem.GetAttack()<<endl<<myItem.GetDefense()<<endl<<myItem.GetHealth()<<endl<<myItem.GetCost()<<endl;
    cout<<myItem.GetConsumable()<<endl;
    //char carray[] = {'A','B', 'C'};
    //cout<<carray[-2];
    //system("PAUSE");  
    return 0;
}