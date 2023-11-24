#include "raylib.h"
#include "Pipe.h"

struct Obstacle
{
	Pipe pipeUp;
	Pipe pipeDown;
	float speed;
	bool isHit;
};

void InitRandom();
Obstacle CreateObstacle();
//Obstacle CreateObstacle2(float posX);
void MoveObstacle(Obstacle& obstacle);
//void MoveObstacle2(Obstacle& obstacle);
void DrawObstacle(Obstacle& obstacle);
void UpdateObstacle(Obstacle& obstacle);
//void UpdateObstacle2(Obstacle& obstacle);
Rectangle GetRecObstacleUp(Obstacle& obstacle);
Rectangle GetRecObstacleDown(Obstacle& obstacle);
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

