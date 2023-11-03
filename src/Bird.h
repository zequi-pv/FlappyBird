#include "raylib.h"

struct Bird
{
    Vector2 pos;
    short int vidas;
    Vector2 size;
    float speed;
    Color color;
  
};

Bird CreateBird();
void DrawBird(Bird bird);
void MoveBird(Bird& bird);
void UpdateBird(Bird& bird);
Rectangle GetBirdRect(Bird bird);
