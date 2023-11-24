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
	Parallax foreGround;
	Parallax midGround;
	Parallax backGround;

	float scrollingBack = 0.0f;
	float scrollingMid = 0.0f;
	float scrollingFore = 0.0f;

	void initializeParallax();
	void moveParallax();
	void drawParallax(Texture2D& background, Texture2D& foreground);

	Parallax InitParallax(Texture2D parallax);
	void DrawParallax(Parallax image);

}