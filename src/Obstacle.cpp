#include "Obstacle.h"

//void CalculateRandom(Obstacle& obstacle)
//{
//}

Obstacle CreateObstacle()
{
	Obstacle obstacle;
	obstacle.pos = { static_cast<float>(GetScreenWidth() / 2) - 500, static_cast<float> (GetScreenHeight() / 2) };
	obstacle.size = { 50,110 };
	obstacle.speed = 100;
	obstacle.color = BLUE;
	return obstacle;
}

void MoveObstacle(Obstacle& obstacle)
{
	obstacle.pos.x = obstacle.speed * GetFrameTime();
	
}

void DrawObstacle(Obstacle& obstacle)
{
	DrawRectangle(obstacle.pos.x - obstacle.size.x, obstacle.pos.y - obstacle.size.y, obstacle.size.x, obstacle.size.y, obstacle.color);
}

void UpdateObstacle(Obstacle& obstacle)
{
	MoveObstacle(obstacle);
}

Rectangle GetRecObstacle(Obstacle& obstacle)
{
	return Rectangle{ obstacle.pos.x - obstacle.size.x / 2, obstacle.pos.y - obstacle.size.y / 2, obstacle.size.x, obstacle.size.y };
}
