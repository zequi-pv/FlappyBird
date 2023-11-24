#include "Pipe.h"

Pipe initPipeUp()
{
	Pipe pipeUp;
	pipeUp.pos = { 0,0 };
	pipeUp.size = { 100.0f, 400.0f };
	pipeUp.color = RED;
	return pipeUp;
}

Pipe initPipeDown()
{
	Pipe pipeDown;
	pipeDown.pos = { 0,0 };
	pipeDown.size = { 100.0f, 400.0f };
	pipeDown.color = RED;
	return pipeDown;
}