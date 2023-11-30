#include <iostream>
#include "raylib.h"
//#include "WindowSize.h"
#include "Bird.h"

using namespace std;

namespace game
{
    Bird CreateBird(Texture2D birdTexture)
    {
        Bird bird;
        bird.pos = { static_cast<float>(GetScreenWidth() / 2) - 400, static_cast<float> (GetScreenHeight() / 2) };
        bird.size = { 90,70 };
        bird.lives = 3;
        bird.score = 0;
        bird.speed = 0.0f;
        bird.aceleration = 0.0f;
        bird.gravity = 400.0f;
        bird.color = RAYWHITE;
        bird.texture = birdTexture;
        bird.isJumping = false;

        return bird;
    }

    void DrawBird(Bird& bird, Texture2D playerTex2)
    {
        if (bird.isJumping)
        {
            DrawTexture(playerTex2, static_cast<int>(bird.pos.x), static_cast<int>(bird.pos.y), bird.color);
        }
        else
        {
            DrawTexture(bird.texture, static_cast<int>(bird.pos.x), static_cast<int>(bird.pos.y), bird.color);
        }
    }

    void MoveBird(Bird& bird, Sound jumpS)
    {
        if (bird.pos.y < 0)
        {
            bird.pos.y = 0;
        }
        if (IsKeyPressed(KEY_W))
        {
            PlaySound(jumpS);
            bird.aceleration = 0.0f;
            bird.speed = bird.gravity / 2;
            bird.isJumping = true;
        }
        else
        {
            if (bird.aceleration >= bird.gravity)
            {
                bird.aceleration = bird.gravity;
                bird.isJumping = false;
            }

            bird.aceleration += bird.gravity * GetFrameTime();
            bird.speed -= bird.aceleration * GetFrameTime();
            bird.pos.y -= bird.speed * GetFrameTime();
        }
    }

    void MoveBird2(Bird& bird, Sound jumpS)
    {
        if (bird.pos.y < 0)
        {
            bird.pos.y = 0;
        }
        if (IsKeyPressed(KEY_UP))
        {
            PlaySound(jumpS);
            bird.aceleration = 0.0f;
            bird.speed = bird.gravity / 2;
            bird.isJumping = true;
        }
        else
        {
            if (bird.aceleration >= bird.gravity)
            {
                bird.aceleration = bird.gravity;
                bird.isJumping = false;
            }

            bird.aceleration += bird.gravity * GetFrameTime();
            bird.speed -= bird.aceleration * GetFrameTime();
            bird.pos.y -= bird.speed * GetFrameTime();
        }
    }

    void UpdateBird(Bird& bird, Sound jumpS)
    {
        MoveBird(bird, jumpS);
    }

    void UpdateBird2(Bird& bird, Sound jumpS)
    {
        MoveBird2(bird, jumpS);
    }

    Rectangle GetBirdRect(Bird bird)
    {
        return Rectangle{ bird.pos.x ,bird.pos.y , bird.size.x,bird.size.y };
    }
}