#ifndef MAINGAME_H
#define MAINGAME_H

#include "InputHandler.h"
#include "Display.h"
#include "Level.h"
#include "GameObject.h"

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

        Display display;
        InputHandler input;
        Level currentLevel;
        
        bool isRunning_;
        GameObject* gameObjects_[16];
        int numberOfObjects_ = 0;
};


#endif /* MAINGAME_H */