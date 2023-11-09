#include "raylib.h"

struct Obstacle
{
	Vector2 pos;
	Vector2 size;
	float speed;
	Color color;
	bool hit;
};

void InitRandom();
Obstacle CreateObstacle();
void MoveObstacle(Obstacle& obstacle);
void DrawObstacle(Obstacle& obstacle);
void UpdateObstacle(Obstacle& obstacle);
Rectangle GetRecObstacle(Obstacle& obstacle);
void ResetObject(Obstacle obstacle);