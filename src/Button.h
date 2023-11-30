#pragma once
#include "raylib.h"

struct Button
{
	Texture2D button;
	Texture2D buttonS;
	Vector2 pos;
	Vector2 size;
	bool isSelected;
};


Button initButtonTex(Vector2 size, Texture2D buttonN, Texture2D buttonS);