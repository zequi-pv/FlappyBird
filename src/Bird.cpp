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
	bird.maxSpeed = 150.0f;
	bird.color = RED;
	bird.texture = birdTexture;
	bird.isJumping = false;
	return bird;
}

void DrawBird(Bird bird)
{
	DrawRectangle(static_cast<int>(bird.pos.x), static_cast<int>(bird.pos.y), static_cast<int>(bird.size.x), static_cast<int>(bird.size.y), bird.color);
	DrawTexture(bird.texture, static_cast<int>(bird.pos.x), static_cast<int>(bird.pos.y), bird.color);
}


void MoveBird(Bird& bird)
{
    float gravity = 800.0f;  // Gravedad
    float jumpAcceleration = -500.0f;  // Ajusta esta aceleración para controlar el salto

    if (IsKeyPressed(KEY_SPACE) && !bird.isJumping)
    {
        bird.isJumping = true;
        bird.speed = jumpAcceleration;
    }
   

    if (bird.isJumping)
    {
        bird.pos.y += bird.speed * GetFrameTime();
        bird.speed += gravity * GetFrameTime();

        //// Cuando el pájaro alcanza su punto más bajo, deja de saltar
        if (bird.pos.y >= GetScreenHeight() - bird.size.y)
        {
            
        bird.isJumping = false;
            bird.pos.y = GetScreenHeight() - bird.size.y;
        }
        

#ifdef _DEBUG
        cout << "y:" << bird.pos.y << endl;
#endif
    }
    else
    {
       
        // Aplica la gravedad al pájaro cuando no está saltando
        bird.pos.y += gravity * GetFrameTime();

        // Limita la posición del pájaro para que no se salga de la pantalla
        if (bird.pos.y > GetScreenHeight() - bird.size.y)
        {
            bird.pos.y = GetScreenHeight() - bird.size.y;
        }

#ifdef _DEBUG
        cout << "y:" << bird.pos.y << endl;
#endif
    }
    }

//void MoveBird(Bird& bird)
//{
//	/*bird.pos.y += bird.speed * GetFrameTime();*/
//	/*if (bird.pos.y > 0|| bird.pos.y < GetScreenHeight() - 50)
//	{*/
//		if (IsKeyPressed(KEY_SPACE) && bird.pos.y > 0)
//		{
//			bird.pos.y -=500  * bird.speed * GetFrameTime();
//			
//
//
//#ifdef _DEBUG
//			cout << "y:" << bird.pos.y << endl;
//#endif
//		}
//		else if (bird.pos.y < GetScreenHeight() - 50)
//		{
//			bird.pos.y += 1 * bird.speed * GetFrameTime();
//
//#ifdef _DEBUG
//			cout << "y:" << bird.pos.y << endl;
//#endif	
//		}	
//	/*}*/
//}

void UpdateBird(Bird& bird)
{
	MoveBird(bird);
}

Rectangle GetBirdRect(Bird bird)
{
	return Rectangle{bird.pos.x - bird.size.x / 2,bird.pos.y - bird.size.y / 2, bird.size.x,bird.size.y };
}

//void BirdInput(Bird bird)
//{
//	if (IsKeyPressed(KEY_SPACE)&&!bird.isJumping)
//	{
//		
//	}
//
//
//}