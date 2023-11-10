#include "raylib.h"

struct Bird
{
    Vector2 pos;
    Texture2D texture;
    Vector2 size;
    Color color;
    short int vidas;
    float speed;
    float aceleration;
    float gravity;
};

Bird CreateBird(Texture2D birdTexture);
void DrawBird(Bird bird);
void MoveBird(Bird& bird);
void UpdateBird(Bird& bird);
Rectangle GetBirdRect(Bird bird);
void BirdInput(Bird bird);
