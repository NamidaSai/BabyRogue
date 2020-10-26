#ifndef SCENE_H
#define SCENE_H

#define MAX_OBJECTS 32

#include "Level.h"
#include "Display.h"
#include "GameObject.h"

class Scene
{
    public:
        Scene();
        Scene(string levelName);

        void Start();
        void Update();
        void Render();
    
    private:
        Display display;
        Level level;
        
        GameObject* gameObjects_[MAX_OBJECTS];
        int numberOfObjects_ = 0;
};

#endif /* SCENE_H */