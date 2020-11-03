#include <iostream>

#include "MainGame.h"
#include "Monster.h"

int main()
{
    // MainGame game;
    // game.RunGame();
    char sprite_= 'T';
    Monster monster(sprite_);
    cout<<monster.GetType()<<endl<<monster.GetAttack()<<endl<<monster.GetDefense()<<endl<<monster.GetHealth()<<endl<<monster.GetSprite()<<endl;
    sprite_ = 'G';
    Monster monster2(sprite_);
    cout<<monster2.GetType()<<endl<<monster2.GetAttack()<<endl<<monster2.GetDefense()<<endl<<monster2.GetHealth()<<endl<<monster2.GetSprite()<<endl;

    //system("PAUSE");
    return 0;
}