#include "Level.h"

#include <iostream>
#include <fstream>

Level::Level(string levelName)
{
    levelName_ = levelName;
}

void Level::LoadLevel()
{
    ifstream inputFile;

    inputFile.open(levelName_);
    if (inputFile.fail())
    {
        perror(levelName_.c_str());
        return;
    }

    for (int y = 0; y < height_; ++y)
    {
        string row;
        if (inputFile >> row)
        {
            for (int x = 0; x < width_; ++x)
            {
                layout_[y][x] = row[x];
            }
        }
        else
        {
            break;
        }
    }

}

void Level::PrintLevel()
{
    for (int y = 0; y < height_; ++y)
    {
        for (int x = 0; x < width_; ++x)
        {
            cout << layout_[y][x];
        }
        cout << endl;
    }
}