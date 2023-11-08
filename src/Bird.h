#include "raylib.h"

struct Bird
{
    Vector2 pos;
    short int vidas;
    Vector2 size;
    float speed;
    Color color;
    Texture2D texture;
};

Bird CreateBird(Texture2D birdTexture );
void DrawBird(Bird bird);
void MoveBird(Bird& bird);
void UpdateBird(Bird& bird);
Rectangle GetBirdRect(Bird bird);
