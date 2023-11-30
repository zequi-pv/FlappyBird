#include "Parallax.h"
#include "Parallax.h"


namespace game
{
	void drawParallax(float& scrollingBack, float& scrollingMid, float& scrollingFore, Texture2D foreGround, Texture2D midGround, Texture2D backGround, bool paused, bool gameOver)
	{
		if (!paused && !gameOver)
		{
			scrollingBack -= 10.0f * GetFrameTime();
			scrollingMid -= 50.0f * GetFrameTime();
			scrollingFore -= 100.0f * GetFrameTime();

			if (scrollingBack <= -backGround.width * 2) scrollingBack = 0;
			if (scrollingMid <= -midGround.width * 2) scrollingMid = 0;
			if (scrollingFore <= -foreGround.width * 2) scrollingFore = 0;
		}

		DrawTextureEx(backGround, Vector2 { scrollingBack, 250 }, 0.0f, 3.0f, RAYWHITE);
		DrawTextureEx(backGround, Vector2 { backGround.width * 3 + scrollingBack, 250 }, 0.0f, 3.0f, RAYWHITE);
		DrawTextureEx(backGround, Vector2 { static_cast<float>((backGround.width * 3 + scrollingBack) + (GetScreenWidth() / 8.0f)), 250 }, 0.0f, 3.0f, RAYWHITE);

		DrawTextureEx(midGround, Vector2 { scrollingMid, 350 }, 0.0f, 3.0f, RAYWHITE);
		DrawTextureEx(midGround, Vector2 { midGround.width * 3 + scrollingMid, 350 }, 0.0f, 3.0f, RAYWHITE);
		DrawTextureEx(midGround, Vector2 { static_cast<float>((midGround.width * 3 + scrollingMid) + (GetScreenWidth() / 8.0f)), 350 }, 0.0f, 3.0f, RAYWHITE);

		DrawTextureEx(foreGround, Vector2 { scrollingFore, 310 }, 0.0f, 3.0f, RAYWHITE);
		DrawTextureEx(foreGround, Vector2 { static_cast<float>(foreGround.width * 3 + scrollingFore), 310 }, 0.0f, 3.0f, RAYWHITE);
		DrawTextureEx(foreGround, Vector2 { static_cast<float>((foreGround.width * 3) + scrollingFore) + (GetScreenWidth() / 5.82f), 310}, 0.0f, 3.0f, RAYWHITE);
		
	}
}