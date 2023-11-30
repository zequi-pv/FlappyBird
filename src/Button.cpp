#include "Button.h"
#include "Utils.h"

Button initButtonTex(Vector2 size, Texture2D buttonN, Texture2D buttonS)
{
	Button button;
	button.button = buttonN;
	button.buttonS = buttonS;
	button.pos;
	button.size = { size.x, size.y };
	button.isSelected = false;
	return button;
}