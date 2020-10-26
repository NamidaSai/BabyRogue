#include "MainGame.h"

#include <iostream>

MainGame::MainGame()
{
    isRunning_ = true;
    input = InputHandler();
    display = Display();
}

void MainGame::RunGame()
{
    std::cout << "Press any key to start. (ESC to Quit)\n";

    while (isRunning_)
    {
        Update();
        Render();
        ProcessInput();
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
    if (in == 'q')
    {
        EndGame();
    }
}

void MainGame::Update()
{
}

void MainGame::Render()
{
    display.ClearCanvas();
    display.GameCanvas();
}
