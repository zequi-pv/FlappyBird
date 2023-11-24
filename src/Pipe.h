#pragma once
#include "raylib.h"

namespace game
{
	struct Pipe
	{
		Vector2 size;
		Vector2 pos;
		Color color;
	};

	Pipe initPipe();
}