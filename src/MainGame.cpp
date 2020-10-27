#include "MainGame.h"

#include <iostream>
#include <conio.h>

MainGame::MainGame()
{
    isRunning_ = true;
    display = Display();
    player = Player();
}


/******************** PUBLIC FUNCTIONS ********************/


void MainGame::RunGame()
{
    LoadLevels();
    std::cout << "Press any key to start. (Q to Quit)\n";
    system("PAUSE");

    player.Spawn(levels_[currentLevel_]);
    Render();
    GameLoop();
}

void MainGame::EndGame()
{
    isRunning_ = false;
}


/******************** PRIVATE FUNCTIONS ********************/


void MainGame::GameLoop()
{
    while (isRunning_)
    {
        ProcessInput();
        Update();
        Render();
    }
}

void MainGame::ProcessInput()
{
    char input = getch();
    if (input == 'q')
    {
        EndGame();
    }
    else
    {
        player.HandleInput(input, levels_[currentLevel_]);
    }
}

void MainGame::Update()
{
    SwitchLevel();
}

void MainGame::Render()
{
    display.ClearCanvas();
    display.GameCanvas(levels_[currentLevel_]);
}

void MainGame::SwitchLevel()
{
    if (levels_[currentLevel_].isLoadNext() && currentLevel_ < MAX_LEVELS)
    {
        currentLevel_++;
        player.Spawn(levels_[currentLevel_]);
    }
    else if (levels_[currentLevel_].isLoadPrev() && currentLevel_ > 0)
    {
        currentLevel_--;
        player.Spawn(levels_[currentLevel_]);
    }
    else if (currentLevel_ >= numberOfLevels_)
    {
        EndGame();
    }
    else
    {
        return;
    }
}

void MainGame::LoadLevels()
{
    Level maze("Levels/Maze.txt");
    levels_[0] = maze;
    numberOfLevels_++;

    Level barracks("Levels/Barracks.txt");
    levels_[1] = barracks;
    numberOfLevels_++;
}