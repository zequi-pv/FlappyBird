#pragma once
#include "raylib.h"
#include"WindowSize.h"

namespace game
{
	void drawParallax(float& scrollingBack, float& scrollingMid, float& scrollingFore, Texture2D foreGround, Texture2D midGround, Texture2D backGround, bool paused, bool gameOver);
}