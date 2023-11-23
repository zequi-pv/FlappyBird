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
Obstacle CreateObstacle(float posX);
Obstacle CreateObstacle2(float posX);
void MoveObstacle(Obstacle& obstacle);
void MoveObstacle2(Obstacle& obstacle);
void DrawObstacle(Obstacle& obstacle);
void UpdateObstacle(Obstacle& obstacle);
void UpdateObstacle2(Obstacle& obstacle);
Rectangle GetRecObstacle(Obstacle& obstacle);
void ResetObject(Obstacle obstacle);

//#include "raylib.h"
//
//// Estructura para manejar un par de obstáculos
//struct ObstaclePair
//{
//    Obstacle top;
//    Obstacle bottom;
//};
//
//void InitRandom();
//ObstaclePair CreateObstaclePair();
//void MoveObstaclePair(ObstaclePair& pair);
//void DrawObstaclePair(ObstaclePair& pair);
//void UpdateObstaclePair(ObstaclePair& pair);
//Rectangle GetRecObstacle(ObstaclePair& pair);
//void ResetObject(ObstaclePair& pair);

