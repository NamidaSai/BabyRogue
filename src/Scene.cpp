#include "Scene.h"
#include "Player.h"

Scene::Scene()
{
    display = Display();
    level = Level("Levels/sandbox.txt");
    numberOfObjects_ = 0;
}

Scene::~Scene()
{
    for (int i = 0; i < MAX_OBJECTS; ++i)
    {
        delete gameObjects_[i];
    }
}

Scene::Scene(string levelName)
{
    display = Display();
    level = Level(levelName);
}

void Scene::Start()
{
    Player player;
    gameObjects_[0] = &player;      // causes "pure virtual method called, terminate called without an active exception" from ~GameObject()
    numberOfObjects_++;
    player.SetX(5);
    player.SetY(5);
}

void Scene::Update()
{
    for (int i = 0; i < numberOfObjects_; ++i)
    {
        gameObjects_[i]->Update();
    }
}

void Scene::Render()
{
    display.ClearCanvas();
    display.GameCanvas(level);
}
