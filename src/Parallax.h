//#pragma once
#include "raylib.h"
//#include"WindowSize.h"
//
//struct Parallax
//{
//	Vector2 pos;
//	Vector2 size;
//	Texture2D texture;
//};
//Parallax foreGround[2];
//Parallax backGround[2];
////extern Parallax backGround[3];
//
//float scrollingBack;
//float scrollingMid;
//
//void initializeParallax();
//void moveParallax();
//void drawParallax(Texture2D& background, Texture2D& foreground);

struct Parallax
{
	Vector2 pos;
	Vector2 size;
	Texture2D texture;
	Color color;
};

Parallax InitParallax(Texture2D parallax);
void DrawParallax(Parallax image);

