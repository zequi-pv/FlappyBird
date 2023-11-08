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
	bird.speed = 100;
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
	if (IsKeyDown(KEY_UP) && bird.pos.y > 0)
	{
	    bird.pos.y -=bird.speed* GetFrameTime();
       
        #ifdef _DEBUG
		cout << "y:" << bird.pos.y << endl;
        #endif
	}
	if (IsKeyDown(KEY_DOWN) && bird.pos.y < GetScreenHeight()-50)
	{
		bird.pos.y += bird.speed * GetFrameTime();

		#ifdef _DEBUG
				cout << "y:" << bird.pos.y << endl;
		#endif	
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