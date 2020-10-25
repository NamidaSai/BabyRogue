#ifndef MAINGAME_H
#define MAINGAME_H

#include "Level.h"
#include "InputHandler.h"

class MainGame
{
    public:
        MainGame();
        void RunGame();
        void EndGame();

    private:
        void ProcessInput();
        void Update();
        void Render(Level level);

        InputHandler input;
        
        bool isRunning_;
};


#endif /* MAINGAME_H */