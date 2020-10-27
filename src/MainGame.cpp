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

    int targetX = x;
    int targetY = y;

    switch (input)
    {
        case 'w':
            targetY = y - 1;
            break;
        case 's':
            targetY = y + 1;
            break;
        case 'a':
            targetX = x - 1;
            break;
        case 'd':
            targetX = x + 1;
            break;
        default:
            break;
    }

    if (PlayerCanMoveToTarget(targetX, targetY))
    {
        currentLevel.ResetTile(x, y);
        player.SetPosition(targetX, targetY);
    }
    else
    {
        cout << "Can't move there!\n";
    }
}

bool MainGame::PlayerCanMoveToTarget(int x, int y)
{
    switch (currentLevel.GetTile(x, y))
    {
        case '.':
            return true;
        case '#':
            return false;
        default:
            return false;
    }
}
