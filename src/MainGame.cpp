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

void MainGame::RunGame()
{
    std::cout << "Press any key to start. (Q to Quit)\n";
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
    char input = getch();
    if (input == 'q')
    {
        EndGame();
    }
    else
    {
        HandlePlayerMovement(input);
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

void MainGame::HandlePlayerMovement(char input)
{
    int x = player.GetX();
    int y = player.GetY();

    switch (input)
    {
        case 'w':
            currentLevel.ResetTile(x, y); 
            player.SetPosition(x, y-1);
            break;
        case 's':
            currentLevel.ResetTile(x, y); 
            player.SetPosition(x, y+1);
            break;
        case 'a':
            currentLevel.ResetTile(x, y); 
            player.SetPosition(x-1, y);
            break;
        case 'd':
            currentLevel.ResetTile(x, y); 
            player.SetPosition(x+1, y);
            break;
        default:
            break;
    }
}
