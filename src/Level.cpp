#include "Level.h"

#include <iostream>
#include <fstream>

Level::Level()
{
    levelName_ = "Levels/sandbox.txt";
    LoadLevel();
}

Level::Level(string levelName)
{
    levelName_ = "Levels/" + levelName + ".txt";
    LoadLevel();
}


/******************** PUBLIC FUNCTIONS ********************/


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

char Level::GetTile(int x, int y)
{
    if (x > width_ || y > height_)
    {
        cout << "The tile at x = " << x << " and y = " << y << " is out of the level's range.\n";
        return 0;
    }
    else
    {
        return layout_[y][x];
    }
}

void Level::SetTile(int x, int y, char tile)
{
    if (x > width_ || y > height_)
    {
        cout << "The tile at x = " << x << " and y = " << y << " is out of the level's range.\n";
        return;
    }
    else
    {
        layout_[y][x] = tile;
    }
}

void Level::ResetTile(int x, int y)
{
    if (x > width_ || y > height_)
    {
        cout << "The tile at x = " << x << " and y = " << y << " is out of the level's range.\n";
        return;
    }
    else
    {
        layout_[y][x] = '.';
    }
    
}

Monster Level::GetMonster(int x, int y)
{
    for (int i = 0; i < monsters_.size(); ++i)
    {
        if (monsters_[i].GetX() == x && monsters_[i].GetY() == y)
        {
            return monsters_[i];
        }
        else
        {
            continue;
        }
    }

    cout << "No monster found at position " << x << "," << y << endl;
    return 0;
}


/******************** PRIVATE FUNCTIONS ********************/


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
            for (unsigned int x = 0; x < width_; ++x)
            {
                if (x >= row.length())
                {
                    layout_[y][x] = '#';
                }
                else
                {
                    layout_[y][x] = row[x];
                }
            }
        }
        else
        {
            for (unsigned int x = 0; x < width_; ++x)
            {
                layout_[y][x] = '#';
            }
        }
    }
}

void Level::LoadObjects()
{
    for (int y = 0; y < height_; ++y)
    {
        for (int x = 0; x < width_; ++x)
        {
            switch(layout_[y][x])
            {
                case '#':
                    break;
                case '.':
                    break;
                case 'Y':
                    break;
                case 'Z':
                    break;
                case '@':
                    break;
                case '$':
                    SpawnShop(x, y);
                    break;
                default:
                    SpawnMonster(x, y, layout_[y][x]);
                    break;
            }
        }
    }
}

void Level::SpawnMonster(int x, int y, char sprite)
{
    Monster monster(sprite);
    monster.SetPosition(x, y);
    monsters_.push_back(monster);
}

void Level::SpawnShop(int x, int y)
{
}