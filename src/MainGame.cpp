#include "MainGame.h"
#include "Player.h"

#include <iostream>

MainGame::MainGame()
{
    isRunning_ = true;
    input = InputHandler();
    display = Display();
    currentLevel = Level();
}

void MainGame::RunGame()
{
    std::cout << "Press any key to start. (ESC to Quit)\n";
    ProcessInput();
    GameLoop();
}

void MainGame::EndGame()
{
    isRunning_ = false;
}


//******************** PRIVATE FUNCTIONS ********************//


void MainGame::GameLoop()
{
    Player player;
    gameObjects_[0] = &player;
    numberOfObjects_++;

    while (isRunning_)
    {
        Update();
        Render();
        ProcessInput();
    }
}

void MainGame::ProcessInput()
{
    char in = input.GetInput();
    if (in == 'q')
    {
        EndGame();
    }
}

void MainGame::Update()
{
    for (int i = 0; i < numberOfObjects_; ++i)
    {
        gameObjects_[i]->Update();
    }
}

void MainGame::Render()
{
    display.ClearCanvas();
    display.GameCanvas(currentLevel);
}
