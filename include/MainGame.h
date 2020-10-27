#ifndef MAINGAME_H
#define MAINGAME_H

#include "Display.h"
#include "Player.h"
#include "Level.h"

class MainGame
{
    public:
        MainGame();
        
        void RunGame();
        void EndGame();

    private:
        void GameLoop();

        void ProcessInput();
        void Update();
        void Render();

        void HandlePlayerMovement(char input);

        Display display;
        Player player;
        Level currentLevel;

        bool isRunning_;
};


#endif /* MAINGAME_H */