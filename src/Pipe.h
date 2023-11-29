#pragma once
#include "raylib.h"

namespace game
{
	struct Pipe
	{
		Vector2 size;
		Vector2 pos;
		Texture2D texture;
		Color color;
	};

	Pipe initPipe(Texture2D texture);
}