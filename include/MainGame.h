#ifndef MAINGAME_H
#define MAINGAME_H

#define MAX_SCENES 32

#include "InputHandler.h"
#include "Scene.h"

class MainGame
{
    public:
        MainGame();
        void RunGame();
        void EndGame();

    private:
        void InitScenes();
        void GameLoop();

        void ProcessInput();
        void LoadNextScene();

        InputHandler input;

        Scene allScenes_[MAX_SCENES];
        int numberOfScenes_ = 0;
        int currentScene_ = 0;
        
        bool isRunning_;
};


#endif /* MAINGAME_H */