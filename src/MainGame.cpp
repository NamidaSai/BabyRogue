#include "MainGame.h"
#include "Player.h"

#include <iostream>

MainGame::MainGame()
{
    isRunning_ = true;
    input = InputHandler();
    numberOfScenes_ = 0;
    currentScene_ = 0;
}

MainGame::~MainGame()
{
    for (int i = 0; i < MAX_SCENES; ++i)
    {
        delete allScenes_[i];
    }
}

void MainGame::RunGame()
{
    std::cout << "Press any key to start. (Q to Quit)\n";
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
    Scene sandbox("Levels/sandbox.txt");
    allScenes_[0] = &sandbox;
    numberOfScenes_++;
    allScenes_[currentScene_]->Start();
    allScenes_[currentScene_]->Update();
    allScenes_[currentScene_]->Render();
}

void MainGame::GameLoop()
{
    while (isRunning_)
    {
        ProcessInput();
        allScenes_[currentScene_]->Update();
        allScenes_[currentScene_]->Render();
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