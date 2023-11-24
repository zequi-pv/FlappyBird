#include "raylib.h"
#include "Pipe.h"

namespace game
{
	struct Obstacle
	{
		Pipe pipeUp;
		Pipe pipeDown;
		float speed;
		bool isHit;
	};

	Obstacle CreateObstacle();
	void MoveObstacle(Obstacle& obstacle);
	void DrawObstacle(Obstacle& obstacle);
	Rectangle GetRecObstacleUp(Obstacle& obstacle);
	Rectangle GetRecObstacleDown(Obstacle& obstacle);
	void ResetObject(Obstacle obstacle);
}