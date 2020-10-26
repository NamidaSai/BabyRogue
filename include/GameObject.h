#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
    public:
        GameObject()
        : x_(0), y_(0) {}

        virtual void Update() = 0;

        int GetX() { return x_; }
        int GetY() { return y_; }

        void SetX(int x) { x_ = x; }
        void SetY(int y) { y_ = y; }
        
    private:
        int x_, y_; 
};

#endif /* GAMEOBJECT_H */