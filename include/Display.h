#ifndef DISPLAY_H
#define DISPLAY_H

class Display
{
    public:
        Display();
        void ClearCanvas();
        void GameCanvas();

    private:
        int width_ = 119;
        int height_ = 29;
        int widthMargin_ = 2;
        int heightMargin_ = 1;
        char edgeChar = '%';
};

#endif /* DISPLAY_H */