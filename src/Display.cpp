#include "Display.h"
#include "Level.h"

#include <iostream>
#include <cstdio>

using namespace std;

Display::Display()
{
}

void Display::ClearCanvas()
{
    cout << string(height_, '\n');
}

void Display::GameCanvas()
{
    // higher screen margin and border
    cout << string(width_, edgeChar) << endl;
    for (int i = 0; i < heightMargin_; ++i)
    {
        printf("%c%*c\n", edgeChar, (width_-1), edgeChar);
    }

    // Level and HUD

    Level level("Levels/sandbox.txt");

    for (int y = 0; y < level.GetHeight(); ++y)
    {
        printf("%*c", -widthMargin_, edgeChar);

        for (int x = 0; x < level.GetWidth(); ++x)
        {

            cout << level.GetTile(x, y);
        }

        int remainingWidth = (width_ - level.GetWidth() - 2);
        printf("%*c\n", remainingWidth, edgeChar);
    }

    // Event Messages

    int remainingHeight = height_ - level.GetHeight() - (heightMargin_ * 2) - 2;
    for (int y = 0; y < remainingHeight; ++y)
    {
        printf("%c%*c\n", edgeChar, (width_-1), edgeChar);
    }

    // lower screen margin and border
    for (int i = 0; i < heightMargin_; ++i)
    {
        printf("%c%*c\n", edgeChar, (width_-1), edgeChar);
    }
    cout << string(width_, edgeChar) << endl;
}