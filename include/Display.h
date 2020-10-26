#ifndef DISPLAY_H
#define DISPLAY_H

class Display
{
    public:
        Display();
        void ClearCanvas();
        void GameCanvas();

    private:
        int width_ = 140;
        int height_ = 30;
        int widthMargin_ = 2;
        int heightMargin_ = 1;
        char edgeChar = '%';
};

#endif /* DISPLAY_H */