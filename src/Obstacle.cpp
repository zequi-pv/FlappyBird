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

//ObstaclePair CreateObstaclePair()
//{
//    ObstaclePair pair;
//
//    float randomTopHeight = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 200.0f + 50.0f;
//    float randomBottomHeight = static_cast<float>(GetScreenHeight()) - randomTopHeight - 200.0f;
//
//    pair.top.size = { 50,randomTopHeight }; // Altura del obstáculo superior
//    pair.bottom.size = { 50, randomBottomHeight }; // Altura del obstáculo inferior
//
//    pair.top.speed = 500;
//    pair.bottom.speed = 500;
//
//    pair.top.color = BLUE;
//    pair.bottom.color = BLUE;
//    
//    pair.top.hit = false;
//    pair.bottom.hit = false;
//
//    // Posiciones de los obstáculos
//    pair.top.pos = { static_cast<float>(GetScreenWidth()), 0 };
//    pair.bottom.pos = { static_cast<float>(GetScreenWidth()), pair.top.size.y + 200 }; // Espacio de 200 entre los obstáculos
//
//    return pair;
//}
//void MoveObstaclePair(ObstaclePair& pair)
//{
//    pair.top.pos.x -= pair.top.speed * GetFrameTime();
//    pair.bottom.pos.x -= pair.bottom.speed * GetFrameTime();
//
//    if (pair.top.pos.x + pair.top.size.x < 0)
//    {
//        pair.top.pos.x = static_cast<float>(GetScreenWidth());
//        float randomTopHeight = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 200.0f + 50.0f;
//        float randomBottomHeight = static_cast<float>(GetScreenHeight()) - randomTopHeight - 200.0f;
//        pair.top.size = { 50.0f, randomTopHeight };
//        pair.bottom.size = { 50.0f, randomBottomHeight };
//        pair.top.pos.y = 0;
//        pair.bottom.pos.y = randomTopHeight + 200.0f;
//    }
//}
//
//void DrawObstaclePair(ObstaclePair& pair)
//{
//    DrawRectangle(static_cast<int>(pair.top.pos.x), static_cast<int>(pair.top.pos.y), static_cast<int>(pair.top.size.x), static_cast<int>(pair.top.size.y), pair.top.color);
//    DrawRectangle(static_cast<int>(pair.bottom.pos.x), static_cast<int>(pair.bottom.pos.y), static_cast<int>(pair.bottom.size.x), static_cast<int>(pair.bottom.size.y), pair.bottom.color);
//}
//
//void UpdateObstaclePair(ObstaclePair& pair)
//{
//    MoveObstaclePair(pair);
//}
//
//Rectangle GetRecObstacle(ObstaclePair& pair)
//{
//    return Rectangle{ pair.top.pos.x, pair.top.pos.y, pair.top.size.x, pair.top.size.y };
//}
//
//void ResetObject(ObstaclePair& pair)
//{
//    pair.top.pos = { static_cast<float>(GetScreenWidth()), 0 };
//    pair.bottom.pos = { static_cast<float>(GetScreenWidth()), pair.top.size.y + 200.0f }; // Espacio de 200 entre los obstáculos
//}
Obstacle CreateObstacle(float posX)
{
    Obstacle obstacle;
    obstacle.size = { 150.0f, 400.0f };
    obstacle.speed = 150.0f;
    obstacle.color = BLUE;
    obstacle.hit = false;
    obstacle.pos = { posX, 0.0f };

    return obstacle;
}

Obstacle CreateObstacle2(float posX)
{
    Obstacle obstacle;
    obstacle.size = { 150.0f, 400.0f };
    obstacle.speed = 150.0f;
    obstacle.color = BLUE;
    obstacle.hit = false;
    obstacle.pos = { posX, static_cast<float>(GetScreenHeight() - 100) };

    return obstacle;
}

void MoveObstacle(Obstacle& obstacle)
{ 
    obstacle.pos.x -= obstacle.speed * GetFrameTime();

    if (obstacle.pos.x + obstacle.size.x < 0)
    {
        obstacle.pos.x = static_cast<float>(GetScreenWidth());
        obstacle.pos.y = static_cast<float>(obstacle.pos.y);
    }
}

void MoveObstacle2(Obstacle& obstacle)
{
    obstacle.pos.x -= obstacle.speed * GetFrameTime();

    if (obstacle.pos.x + obstacle.size.x < 0)
    {
        obstacle.pos.x = static_cast<float>(GetScreenWidth());
        obstacle.pos.y = static_cast<float>(GetScreenHeight() - 100);
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

void UpdateObstacle2(Obstacle& obstacle)
{
    MoveObstacle2(obstacle);
}

Rectangle GetRecObstacle(Obstacle& obstacle)
{
	return Rectangle{ obstacle.pos.x , obstacle.pos.y , obstacle.size.x, obstacle.size.y };
}

void ResetObject(Obstacle obstacle)
{
    InitRandom();
    obstacle.pos = { static_cast<float>(obstacle.pos.x), static_cast<float>(obstacle.pos.y) };
}