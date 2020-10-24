#include <iostream>

#include "Level.h"

int main()
{
    Level sandbox("Levels/sandbox.txt");
    sandbox.LoadLevel();
    sandbox.PrintLevel();

    system("PAUSE");
    return 0;
}