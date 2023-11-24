#include "Pipe.h"

namespace game
{
	Pipe initPipe()
	{
		Pipe pipe;
		pipe.pos = { 0,0 };
		pipe.size = { 100.0f, 400.0f };
		pipe.color = RED;
		return pipe;
	}
}