#pragma once
#include "raylib.h"

struct Pipe
{
	Vector2 size;
	Vector2 pos;
	Color color;
};

Pipe initPipeUp();
Pipe initPipeDown();