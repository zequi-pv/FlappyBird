#include "Pipe.h"

namespace game
{
	Pipe initPipe(Texture2D texture)
	{
		Pipe pipe;
		pipe.pos = { 0,0 };
		pipe.size = { 100.0f, 400.0f };
		pipe.texture = texture;
		pipe.color = RAYWHITE;
		return pipe;
	}
}