#pragma once
#include "raylib.h"

struct Parallax
{
	Vector2 pos;
	Vector2 size;
};
extern Parallax foreGround[2];
extern Parallax backGround[2];
//extern Parallax backGround[3];

extern float scrollingBack;
extern float scrollingMid;

void initializeParallax();
void moveParallax();
void drawParallax(Texture2D& background, Texture2D& foreground);