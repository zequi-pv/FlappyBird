#include "Obstacle.h"
#include <iostream>
#include <ctime>

using namespace std;

namespace game
{
    Obstacle CreateObstacle(Texture2D obstacleDown, Texture2D obstacleUp)
    {
        Obstacle obstacle;

        obstacle.pipeUp = initPipe(obstacleUp);
        obstacle.pipeDown = initPipe(obstacleDown);
        obstacle.pipeUp.pos = { 0.0f, 0.0f };
        obstacle.pipeDown.pos = { 0.0f, static_cast<float>(GetScreenHeight() - 100) };
        obstacle.speed = 150.0f;
        obstacle.isHit = false;

        return obstacle;
    }

    void MoveObstacle(Obstacle& obstacle)
    {
        obstacle.pipeUp.pos.x -= obstacle.speed * GetFrameTime();
        obstacle.pipeDown.pos.x -= obstacle.speed * GetFrameTime();

        if (obstacle.pipeUp.pos.x + obstacle.pipeUp.size.x < 0 && obstacle.pipeDown.pos.x + obstacle.pipeDown.size.x < 0)
        {
            obstacle.pipeUp.pos.x = static_cast<float>(GetScreenWidth());
            obstacle.pipeUp.pos.y = static_cast<float>(obstacle.pipeUp.pos.y);
            obstacle.pipeDown.pos.x = static_cast<float>(GetScreenWidth());
            obstacle.pipeDown.pos.y = static_cast<float>(obstacle.pipeDown.pos.y);
        }
    }

    void DrawObstacle(Obstacle& obstacle)
    {
        DrawTexture(obstacle.pipeUp.texture, static_cast<int>(obstacle.pipeUp.pos.x), static_cast<int>(obstacle.pipeUp.pos.y), obstacle.pipeUp.color);
        DrawTexture(obstacle.pipeDown.texture, static_cast<int>(obstacle.pipeDown.pos.x), static_cast<int>(obstacle.pipeDown.pos.y), obstacle.pipeDown.color);
        #ifdef _DEBUG
        //DrawRectangle(static_cast<int>(obstacle.pipeUp.pos.x), static_cast<int>(obstacle.pipeUp.pos.y), static_cast<int>(obstacle.pipeUp.size.x), static_cast<int>(obstacle.pipeUp.size.y), obstacle.pipeUp.color);
        //DrawRectangle(static_cast<int>(obstacle.pipeDown.pos.x), static_cast<int>(obstacle.pipeDown.pos.y), static_cast<int>(obstacle.pipeDown.size.x), static_cast<int>(obstacle.pipeDown.size.y), obstacle.pipeDown.color);
        #endif
    }

    Rectangle GetRecObstacleUp(Obstacle& obstacle)
    {
        return Rectangle{ obstacle.pipeUp.pos.x , obstacle.pipeUp.pos.y , obstacle.pipeUp.size.x, obstacle.pipeUp.size.y };
    }

    Rectangle GetRecObstacleDown(Obstacle& obstacle)
    {
        return Rectangle{ obstacle.pipeDown.pos.x , obstacle.pipeDown.pos.y , obstacle.pipeDown.size.x, obstacle.pipeDown.size.y };
    }

    void ResetObject(Obstacle obstacle)
    {
        obstacle.pipeUp.pos = { static_cast<float>(obstacle.pipeUp.pos.x), static_cast<float>(obstacle.pipeUp.pos.y) };
        obstacle.pipeDown.pos = { static_cast<float>(obstacle.pipeDown.pos.x), static_cast<float>(obstacle.pipeDown.pos.y) };
    }
}