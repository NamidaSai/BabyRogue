#include <iostream>

#include "MainGame.h"
#include "Monster.h"

int main()
{
    // MainGame game;
    // game.RunGame();

    Monster monster("Troll");
    cout<<monster.GetType()<<endl<<monster.GetAttack()<<endl<<monster.GetDefense()<<endl<<monster.GetHealth()<<endl;

    Monster monster2("Goblin");
    cout<<monster2.GetType()<<endl<<monster2.GetAttack()<<endl<<monster2.GetDefense()<<endl<<monster2.GetHealth()<<endl;

    system("PAUSE");
    return 0;
}