#include "Display.h"
#include "Level.h"

#include <iostream>

using namespace std;

Display::Display()
{
}

void Display::GameCanvas()
{
    // higher screen margin and border

    for (int i = 0; i < width_; ++i)
    {
        cout << '#';
    }
    cout << endl;

    cout << '#';
    for (int i = 1; i < width_-1; ++i)
    {
        cout << ' ';
    }
    cout << '#';
    cout << endl;

    // Main Screen

    Level level("Levels/sandbox.txt");

    for (int y = 0; y < level.GetHeight(); ++y)
    {
        cout << "# ";

        for (int x = 0; x < level.GetWidth(); ++x)
        {

            cout << level.GetTile(x, y);
        }

        int remainingWidth = (width_ - level.GetWidth() - 3);
        for (int i = 0; i < remainingWidth; ++i)
        {
            cout << ' ';
        }
        cout << '#' << endl;
    }



    // lower screen margin and border
   
    cout << '#';
    for (int i = 1; i < width_-1; ++i)
    {
        cout << ' ';
    }
    cout << '#';
    cout << endl;

    for (int i = 0; i < width_; ++i)
    {
        cout << '#';
    }
    cout << endl;
}