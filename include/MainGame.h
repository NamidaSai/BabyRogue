#ifndef MAINGAME_H
#define MAINGAME_H

#define MAX_LEVELS 2

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

        void SwitchLevel();
        void LoadLevels();

        Display display;
        Player player;

        Level levels_[MAX_LEVELS];
        int numberOfLevels_;
        int currentLevel_ = 0;

        bool isRunning_;
};


#endif /* MAINGAME_H */