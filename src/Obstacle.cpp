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
        obstacle.pointsToGive = 100;
        obstacle.pointsToGiveP2 = 100;
        obstacle.isHit = false;
        obstacle.givenPoints = false;
        obstacle.givenPointsP2 = false;

        return obstacle;
    }

    void MoveObstacle(Obstacle& obstacle)
    {
        obstacle.pipeUp.pos.x -= obstacle.speed * GetFrameTime();
        obstacle.pipeDown.pos.x -= obstacle.speed * GetFrameTime();

        if (obstacle.pipeUp.pos.x + obstacle.pipeUp.size.x < 0 && obstacle.pipeDown.pos.x + obstacle.pipeDown.size.x < 0)
        {
            ResetObject(obstacle);
        }
    }

    void DrawObstacle(Obstacle& obstacle)
    {
        DrawTexture(obstacle.pipeUp.texture, static_cast<int>(obstacle.pipeUp.pos.x), static_cast<int>(obstacle.pipeUp.pos.y), obstacle.pipeUp.color);
        DrawTexture(obstacle.pipeDown.texture, static_cast<int>(obstacle.pipeDown.pos.x), static_cast<int>(obstacle.pipeDown.pos.y), obstacle.pipeDown.color);
    }

    Rectangle GetRecObstacleUp(Obstacle& obstacle)
    {
        return Rectangle{ obstacle.pipeUp.pos.x , obstacle.pipeUp.pos.y , obstacle.pipeUp.size.x, obstacle.pipeUp.size.y };
    }

    Rectangle GetRecObstacleDown(Obstacle& obstacle)
    {
        return Rectangle{ obstacle.pipeDown.pos.x , obstacle.pipeDown.pos.y , obstacle.pipeDown.size.x, obstacle.pipeDown.size.y };
    }

    void ResetObject(Obstacle& obstacle)
    {
        int randHeight = 0;
        randHeight = GetRandomValue(1,2);
        
        switch (randHeight)
        {
        case 1:
            obstacle.pipeUp.pos.y = 0.0f;
            obstacle.pipeDown.pos.y = static_cast<float>(GetScreenHeight() - 100);
            break;
        case 2:
            obstacle.pipeUp.pos.y = static_cast<float>(-250);
            obstacle.pipeDown.pos.y = static_cast<float>(GetScreenHeight() - 350);
            break;
        default:
            break;
        }
        
        obstacle.pipeUp.pos.x = static_cast<float>(GetScreenWidth() + 500.0f);
        obstacle.pipeDown.pos.x = static_cast<float>(GetScreenWidth() + 500.0f);
        obstacle.givenPoints = true;
        obstacle.pointsToGive = 100;  
        obstacle.givenPointsP2 = true;
        obstacle.pointsToGiveP2 = 100;
    }
}