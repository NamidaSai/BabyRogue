#include "MainGame.h"

#include <iostream>
#include <conio.h>

MainGame::MainGame()
{
    isRunning_ = true;
    display = Display();
    player = Player();
    currentLevel = Level();
}


/******************** PUBLIC FUNCTIONS ********************/


void MainGame::RunGame()
{
    std::cout << "Press any key to start. (Q to Quit)\n";
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
        player.HandleInput(input, currentLevel);
    }
}

void MainGame::Update()
{
}

void MainGame::Render()
{
    display.ClearCanvas();
    display.GameCanvas(currentLevel);
}