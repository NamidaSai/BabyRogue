#include "MainGame.h"

#include <iostream>

#define esc 27

MainGame::MainGame()
{
    isRunning_ = true;
    input = InputHandler();
}

void MainGame::RunGame()
{
    Level currentLevel("Levels/sandbox.txt");
    std::cout << "Press any key to start. (ESC to Quit)\n";

    while (isRunning_)
    {
        ProcessInput();
        Update();
        Render(currentLevel);
    }
}

void MainGame::EndGame()
{
    isRunning_ = false;
}



//******************** PRIVATE FUNCTIONS ********************//


void MainGame::ProcessInput()
{
    char in = input.GetInput();
    if (in == esc)
    {
        EndGame();
    }
}

void MainGame::Update()
{
}

void MainGame::Render(Level level)
{
    level.PrintLevel();
}
