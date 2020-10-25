#ifndef MAINGAME_H
#define MAINGAME_H

#include "InputHandler.h"
#include "Display.h"

class MainGame
{
    public:
        MainGame();
        void RunGame();
        void EndGame();

    private:
        void ProcessInput();
        void Update();
        void Render();

        Display display;
        InputHandler input;
        
        bool isRunning_;
};


#endif /* MAINGAME_H */