#include "Parallax.h"

const int size = 1074;
const int offset = 100;
const int sizeback = 1024;
const int offsetback = 0;
//const int size = 1920;
//const int offset = 1080;

void initializeParallax()
{
	backGround[0].size.x = sizeback;
	backGround[0].size.y = 689;
	backGround[0].pos.y = 0;
	backGround[0].pos.x = -offsetback;

	backGround[1].size.x = sizeback;
	backGround[1].size.y = 689;
	backGround[1].pos.y = 0;
	backGround[1].pos.x = size + offsetback - 90;/* backGround[1].size.x;*/

	foreGround[0].size.x = size;
	foreGround[0].size.y = 495;
	foreGround[0].pos.y = 405;
	foreGround[0].pos.x = -offset;

	foreGround[1].size.x = size;
	foreGround[1].size.y = 495;
	foreGround[1].pos.y = 405;
	foreGround[1].pos.x = size - offset - 90/*foreGround[1].size.x - 200*/;

	scrollingBack = 0.5f;
	scrollingMid = 2.0f;
}

void moveParallax()
{

	backGround[0].pos.x -= scrollingBack;
	backGround[1].pos.x -= scrollingBack;

	foreGround[0].pos.x -= scrollingMid;
	foreGround[1].pos.x -= scrollingMid;


	if (backGround[0].pos.x <= 0 - backGround[0].size.x)
	{
		backGround[0].pos.x = backGround[1].pos.x + sizeback + offsetback - 90;


	}
	if (backGround[1].pos.x <= 0 - backGround[1].size.x)
	{
		backGround[1].pos.x = backGround[0].pos.x + sizeback + offsetback - 90;

	}

	if (foreGround[0].pos.x <= 0 - foreGround[0].size.x)
	{
		foreGround[0].pos.x = foreGround[1].pos.x + size - offset - 90;


	}
	if (foreGround[1].pos.x <= 0 - foreGround[1].size.x)
	{
		foreGround[1].pos.x = foreGround[0].pos.x + size - offset - 90;

	}

}

void drawParallax(Texture2D& background, Texture2D& foreground)
{
	DrawTexture(background, backGround[0].pos.x, backGround[0].pos.y, WHITE);
	DrawTexture(background, backGround[1].pos.x, backGround[1].pos.y, WHITE);

	DrawTexture(foreground, foreGround[0].pos.x, foreGround[0].pos.y, WHITE);
	DrawTexture(foreground, foreGround[1].pos.x, foreGround[1].pos.y, WHITE);
}