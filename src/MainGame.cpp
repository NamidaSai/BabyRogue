#include "MainGame.h"

#include <iostream>

MainGame::MainGame()
{
    isRunning_ = true;
    input = InputHandler();
    display = Display();
    player = Player();
    currentLevel = Level();
}

void MainGame::RunGame()
{
    std::cout << "Press any key to start. (Q to Quit)\n";
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
    while (isRunning_)
    {
        ProcessInput();
        Update();
        Render();
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
    currentLevel.SetTile(player.GetX(), player.GetY(), player.GetSprite());
}

void MainGame::Render()
{
    display.ClearCanvas();
    display.GameCanvas(currentLevel);
}