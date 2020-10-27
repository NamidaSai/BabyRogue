#ifndef LEVEL_H
#define LEVEL_H

#include <string>

using namespace std;

class Level
{
    public:
        Level();
        Level(string levelName);

        void PrintLevel();

        void EndLevel(bool value) { isEnded_ = value; }
        bool isEnded() { return isEnded_; }
        
        char GetTile(int x, int y);
        void SetTile(int x, int y, char tile);
        void ResetTile(int x, int y);

        int GetWidth() { return width_; }
        int GetHeight() { return height_; }

    private:
        void LoadLevel();

        string levelName_;
        static const int width_ = 75;
        static const int height_ = 17;
        char layout_[height_][width_];

        bool isEnded_ = false;
};

#endif /* LEVEL_H */