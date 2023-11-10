#include<iostream>
#include"raylib.h"
#include"WindowSize.h"
#include"Bird.h"

using namespace std;

Bird CreateBird(Texture2D birdTexture)
{
	Bird bird;
	bird.pos = { static_cast<float>(GetScreenWidth() / 2)-500, static_cast<float> (GetScreenHeight() / 2) };
	bird.size = { 50,50 };
	bird.vidas = 3;
	bird.speed = 0.0f;
    bird.aceleration = 0.0f;
    bird.gravity = 400.0f;
	bird.color = RED;
	bird.texture = birdTexture;
	
	return bird;
}

void DrawBird(Bird bird)
{
	DrawRectangle(static_cast<int>(bird.pos.x), static_cast<int>(bird.pos.y), static_cast<int>(bird.size.x), static_cast<int>(bird.size.y), bird.color);
	DrawTexture(bird.texture, static_cast<int>(bird.pos.x), static_cast<int>(bird.pos.y), bird.color);
}

void MoveBird(Bird& bird)
{
    if (bird.pos.y>0&&bird.size.y > 0)
    {
        if (IsKeyPressed(KEY_SPACE))
        {
            bird.aceleration = 0.0f;
            bird.speed = bird.gravity / 2;
            cout << "aceleration: " << bird.aceleration << endl;
            cout << "gravity: " << bird.gravity << endl;
            cout << "speed: " << bird.speed << endl;
            cout << "y: " << bird.pos.y << endl;
        }
        else
        {
            if (bird.aceleration >= bird.gravity)
            {
                bird.aceleration = bird.gravity;
            }

            bird.aceleration += bird.gravity * GetFrameTime();
            bird.speed -= bird.aceleration * GetFrameTime();
            bird.pos.y -= bird.speed * GetFrameTime();
            cout << "aceleration: " << bird.aceleration << endl;
            cout << "gravity: " << bird.gravity << endl;
            cout << "speed: " << bird.speed << endl;
            cout << "y: " << bird.pos.y << endl;
        }
    }
}

void UpdateBird(Bird& bird)
{
        MoveBird(bird);
}

Rectangle GetBirdRect(Bird bird)
{
	return Rectangle{bird.pos.x - bird.size.x / 2,bird.pos.y - bird.size.y / 2, bird.size.x,bird.size.y };
}