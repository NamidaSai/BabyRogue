#ifndef LEVEL_H
#define LEVEL_H

#include <string>

using namespace std;

class Level
{
    public:
        Level(string levelName);
        void PrintLevel();
        char GetTile(int x, int y);
        void SetTile(int x, int y, char tile);

        int GetWidth() { return width_; }
        int GetHeight() { return height_; }

    private:
        void LoadLevel();

        string levelName_;
        static const int width_ = 100;
        static const int height_ = 20;
        char layout_[height_][width_];
};

#endif /* LEVEL_H */