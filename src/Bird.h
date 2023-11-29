#include "raylib.h"

namespace game
{
    struct Bird
    {
        Vector2 pos;
        Texture2D texture;
        Vector2 size;
        Color color;
        short int vidas;
        int score;
        float speed;
        float aceleration;
        float gravity;
        bool isJumping;
    };

    Bird CreateBird(Texture2D birdTexture);
    void DrawBird(Bird& bird, Texture2D playerTex2);
    void MoveBird(Bird& bird);
    void MoveBird2(Bird& bird);
    void UpdateBird(Bird& bird);
    void UpdateBird2(Bird& bird);
    Rectangle GetBirdRect(Bird bird);
    void BirdInput(Bird bird);
}