#ifndef MAINGAME_H
#define MAINGAME_H

#define MAX_SCENES 16

#include "InputHandler.h"
#include "Scene.h"

class MainGame
{
    public:
        MainGame();
        ~MainGame();
        
        void RunGame();
        void EndGame();

    private:
        void InitScenes();
        void GameLoop();

        void ProcessInput();
        void LoadNextScene();

        InputHandler input;

        Scene* allScenes_[MAX_SCENES];
        int numberOfScenes_;
        int currentScene_;
        
        bool isRunning_;
};


#endif /* MAINGAME_H */