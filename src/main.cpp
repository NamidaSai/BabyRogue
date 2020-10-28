#include <iostream>

#include "MainGame.h"
#include "Monster.h"

int main()
{
    // MainGame game;
    // game.RunGame();

    Monster monster("Troll");
    cout<<monster.type<<endl<<monster.attack<<endl<<monster.defense<<endl<<monster.health<<endl;

    Monster monster2("Goblin");
    cout<<monster2.type<<endl<<monster2.attack<<endl<<monster2.defense<<endl<<monster2.health<<endl;

    system("PAUSE");
    return 0;
}