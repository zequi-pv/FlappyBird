#include "raylib.h"

namespace game
{
    struct Bird
    {
        Vector2 pos;
        Texture2D texture;
        Vector2 size;
        Color color;
        short int lives;
        int score;
        float speed;
        float aceleration;
        float gravity;
        bool isJumping;
    };


    Bird CreateBird(Texture2D birdTexture);
    void DrawBird(Bird& bird, Texture2D playerTex2);
    void MoveBird(Bird& bird, Sound jumpS);
    void MoveBird2(Bird& bird, Sound jumpS);
    void UpdateBird(Bird& bird, Sound jumpS);
    void UpdateBird2(Bird& bird, Sound jumpS);
    Rectangle GetBirdRect(Bird bird);
    
}