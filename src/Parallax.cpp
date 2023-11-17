#include "Parallax.h"
#include "Parallax.h"

const int size = 1074;
const int offset = 100;
const int sizeback = 1024;
const int offsetback = 0;
//const int size = 1920;
//const int offset = 1080;

void initializeParallax()
{
	backGround.pos.y = 300;
	backGround.pos.x = scrollingBack;
	backGround.scale = 2.0f;
	
	midGround.pos.y = 300;
	midGround.pos.x = scrollingMid;
	midGround.scale = 2.0f;

	foreGround.pos.y = 390;
	foreGround.pos.x = scrollingFore;
	foreGround.scale = 2.0f;
}

void moveParallax()
{
	scrollingBack -= 10.0f * GetFrameTime();
	scrollingMid -= 50.0f * GetFrameTime();
	scrollingFore -= 100.0f * GetFrameTime();

	if (scrollingBack <= -backGround.texture.width * 2) scrollingBack = 0;
	if (scrollingMid <= -midGround.texture.width * 2) scrollingMid = 0;
	if (scrollingFore <= -foreGround.texture.width * 2) scrollingFore = 0;


}

void drawParallax(Texture2D& background, Texture2D& foreground)
{
	DrawTextureEx(backGround.texture, { backGround.pos.x, backGround.pos.y }, 0.0f, backGround.scale, RAYWHITE);
	DrawTextureEx(backGround.texture, { backGround.texture.width * 2 + backGround.pos.x, backGround.pos.y }, 0.0f, backGround.scale, RAYWHITE);
	DrawTextureEx(backGround.texture, { (backGround.texture.width * 3 + backGround.pos.x) + (GetScreenWidth() / 4.0f), backGround.pos.y }, 0.0f, backGround.scale, RAYWHITE );

	DrawTextureEx(midGround.texture, { midGround.pos.x, midGround.pos.y }, 0.0f, midGround.scale, RAYWHITE );
	DrawTextureEx(midGround.texture, { midGround.texture.width * 2 + midGround.pos.x, midGround.pos.y }, 0.0f, midGround.scale, RAYWHITE );
	DrawTextureEx(midGround.texture, { (midGround.texture.width * 3 + midGround.pos.x) + (GetScreenWidth() / 4.0f), midGround.pos.y }, 0.0f, midGround.scale, RAYWHITE);

	DrawTextureEx(foreGround.texture, { foreGround.pos.x, foreGround.pos.y }, 0.0f, foreGround.scale, RAYWHITE);
	DrawTextureEx(foreGround.texture, { foreGround.texture.width * 2 + foreGround.pos.x, foreGround.pos.y }, 0.0f, foreGround.scale, RAYWHITE);
	DrawTextureEx(foreGround.texture, { (foreGround.texture.width * 3 + foreGround.pos.x) + (GetScreenWidth() / 4.0f), foreGround.pos.y }, 0.0f, foreGround.scale, RAYWHITE);
}

Parallax InitParallax(Texture2D parallax)
{
	Parallax image;
	image.pos.x = static_cast<float>(GetScreenWidth())/2;
	image.pos.y = static_cast<float>(GetScreenHeight())/2;
	image.size.x = 0;
	image.size.y = 0;
	image.texture = parallax;
	image.color = RED;
	return image;
	
}

void DrawParallax(Parallax image)
{
	DrawTexture(image.texture, static_cast<int>(image.pos.x), static_cast<int>(image.pos.y), image.color);
}
