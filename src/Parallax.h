#pragma once
#include "raylib.h"
#include"WindowSize.h"

namespace game
{
	struct Parallax
	{
		Texture2D texture;
		Vector2 pos;
		float scale;
	};
	/*Parallax foreGround;
	Parallax midGround;
	Parallax backGround;*/

	

	/*void initializeParallax();*/
	void drawParallax(float scrollingBack, float scrollingMid, float scrollingFore, Parallax foreGround, Parallax midGround, Parallax backGround);

	Parallax InitParallax(Texture2D parallax);
	void DrawParallax(Parallax image);

}