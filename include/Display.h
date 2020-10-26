#ifndef DISPLAY_H
#define DISPLAY_H

#include "Level.h"

class Display
{
    public:
        Display();
        void ClearCanvas();
        void GameCanvas(Level level);

    private:
        int width_ = 119;
        int height_ = 29;
        int widthMargin_ = 2;
        int heightMargin_ = 1;
        char edgeChar = '%';
};

#endif /* DISPLAY_H */