#include "MainGame.h"
#include "Player.h"

#include <iostream>

MainGame::MainGame()
{
    isRunning_ = true;
    input = InputHandler();
}

void MainGame::RunGame()
{
    std::cout << "Press any key to start. (ESC to Quit)\n";
    ProcessInput();
    InitScenes();
    GameLoop();
}

void MainGame::EndGame()
{
    isRunning_ = false;
}


//******************** PRIVATE FUNCTIONS ********************//

void MainGame::InitScenes()
{
    allScenes_[0] = Scene("Levels/sandbox.txt");
    numberOfScenes_++;
}

void MainGame::GameLoop()
{
    while (isRunning_)
    {
        ProcessInput();
        allScenes_[currentScene_].Update();
        allScenes_[currentScene_].Render();
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

void MainGame::LoadNextScene()
{
    currentScene_++;
}