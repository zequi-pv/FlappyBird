#include "Obstacle.h"
#include<iostream>
#include <ctime>
using namespace std;
bool randomInitialized = false;

void InitRandom()
{
    if (!randomInitialized)
    {
        srand(static_cast<unsigned>(time(nullptr)));
        randomInitialized = true;
    }
}

Obstacle CreateObstacle()
{
    Obstacle obstacle;
    obstacle.size = { 50, 110 };
    obstacle.speed = 500;
    obstacle.color = BLUE;
    obstacle.pos = { static_cast<float>(GetScreenWidth()), static_cast<float>(rand() % GetScreenHeight()) };

    return obstacle;
}

void MoveObstacle(Obstacle& obstacle)
{ 
    obstacle.pos.x -= obstacle.speed * GetFrameTime();

    if (obstacle.pos.x + obstacle.size.x < 0)
    {
        obstacle.pos.x = static_cast<float>(GetScreenWidth());
        obstacle.pos.y = static_cast<float>(rand() % GetScreenHeight());
    }
}

void DrawObstacle(Obstacle& obstacle)
{
	DrawRectangle(static_cast<int>(obstacle.pos.x) , static_cast<int>(obstacle.pos.y) , static_cast<int>(obstacle.size.x), static_cast<int>(obstacle.size.y),obstacle.color);
}

void UpdateObstacle(Obstacle& obstacle)
{
	MoveObstacle(obstacle);
}

Rectangle GetRecObstacle(Obstacle& obstacle)
{
	return Rectangle{ obstacle.pos.x , obstacle.pos.y , obstacle.size.x, obstacle.size.y };
}

void ResetObject(Obstacle obstacle)
{
    InitRandom();
    obstacle.pos = { static_cast<float>(GetScreenWidth()), static_cast<float>(rand() % GetScreenHeight()) };
}