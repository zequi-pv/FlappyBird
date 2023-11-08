#include<iostream>
#include"Game.h"
#include"WindowSize.h"
#include"Bird.h"
#include"Obstacle.h"

using namespace std;

static void Init();
static void MainLoop();
static void Close();
void Update();
void BirdCollition(Bird& bird, Obstacle& obstacle);
//void DrawPause();
/*static void Draw();
static void DrawCredit();
void GameLoop();
void WindowInstructions();
void UpdateMenu();
void CreditsWindow();
void InitializTexts();*/
Texture2D playerTexture;
Bird bird;
Obstacle obstacle;

/*static*/ bool exitWindow = false;
/*static*/ bool pause = false;
/*static*/ bool salir = false;

namespace game
{
	void RunGame()
	{
		Init();
		MainLoop();
		Close();
	}
}

static void Init()
{
	InitWindow(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGTH), "ASTEROIDS");
	SetExitKey(KEY_NULL);
	playerTexture = LoadTexture("res/playerShip2_orange.png");
	bird = CreateBird(playerTexture);
	obstacle = CreateObstacle();
}

/*static*/ void MainLoop()
{
	while (!exitWindow)
	{
		while (!WindowShouldClose() && !salir)
		{
			GameLoop();
			//ScenesSwitch();
			exitWindow = true;
		}
	}
}

void Update()
{
	UpdateBird(bird);
	UpdateObstacle(obstacle);
	BirdCollition(bird,obstacle);
}

/*static*/ void Close()
{
	UnloadTexture(playerTexture);
	CloseWindow();
}

/*static*/ void Draw()
{
	BeginDrawing();
	ClearBackground(WHITE);
	DrawRectangle(0, 0, 5, GetScreenHeight(), Fade(WHITE, 1.0f));
	DrawRectangle(GetScreenWidth() - 5, 0, 5, GetScreenHeight(), Fade(WHITE, 1.0f));

	DrawBird(bird);
	DrawObstacle(obstacle);
	//if (pause)
	//{
	//	//DrawPause();
	//}
	//else
	//{
	//	
	//}
	DrawCredit();
	EndDrawing();
}
/*static*/ void DrawCredit()
{
	DrawText(TextFormat("Credit: Leonardo Brizuela, V 0.1"), GetScreenWidth() / 2 - 500, GetScreenHeight() / 2 + 350, 25, RED);
}

/*static*/ void GameLoop()
{
	//if (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_P))
	//{
	//	pause = !pause;
	//	cout << "pause" << endl;
	//	cout << pause << endl;
	//	//DrawPause();
	//}

	//if (!pause)
	//{
	//	Update();
	//}
	//else
	//{
	//	DrawPause();

	//	if (IsKeyPressed(KEY_R))
	//	{
	//		
	//	}
	//	else if (IsKeyPressed(KEY_ESCAPE))
	//	{
	//		
	//	}
	//}
	Update();
	Draw();
}

void BirdCollition(Bird& player, Obstacle& obs)
{
	if (CheckCollisionRecs(GetBirdRect(player),GetRecObstacle(obs)))
	{
		player.vidas-=1;
		bird.pos = { static_cast<float>(GetScreenWidth() / 2) - 500, static_cast<float> (GetScreenHeight() / 2) };
		#ifdef _DEBUG
				cout << "vidas" << player.vidas << endl;
		#endif
	}

}
//void WindowInstructions()
//{
//	BeginDrawing();
//
//	DrawRectangleGradientV(GetScreenWidth() / 2 - 512, GetScreenHeight() / 2 - 384, 1024, 768, BEIGE, Fade(RED, 1.0f));
//	DrawText("Use Up/Down to move rigth paddles", GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 - 10, 40, WHITE);
//	DrawText("Use W/S to move left paddles", GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 - 100, 40, WHITE);
//	//DrawText("(ESC) Back", GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 + 200, 40, WHITE);
//
//	DrawBack();
//	CheckBack();
//	EndDrawing();
//
//	backMenu();
//}
//
//void UpdateMenu()
//{
//	CheckSinglePlayer();
//	CheckInstructions();
//	CheckCredits();
//	CheckBack();
//	CheckQuit();
//}
//
//void CreditsWindow()
//{
//	BeginDrawing();
//
//	DrawRectangleGradientV(GetScreenWidth() / 2 - 512, GetScreenHeight() / 2 - 384, 1024, 768, BEIGE, Fade(RED, 1.0f));
//	DrawText("Code by: Leonardo Brizuela", GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 - 10, 40, WHITE);
//	//DrawText("(ESC) Back", GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 + 200, 40, WHITE);
//	DrawBack();
//	CheckBack();
//	EndDrawing();
//	backMenu();
//
//
//}
//
//void backMenu()
//{
//	if (IsKeyPressed(KEY_ESCAPE))
//	{
//		menu = MenuScenes::MainMenu;
//	}
//}
//
//void DrawPause()
//{
//	BeginDrawing();
//
//	DrawRectangleGradientV(GetScreenWidth() / 2 - 512, GetScreenHeight() / 2 - 384, 1024, 768, BEIGE, Fade(RED, 1.0f));
//	DrawText("Pause", GetScreenWidth() / 2 - 140, GetScreenHeight() / 2 - 250, 100, WHITE);
//	DrawText("Press (P) to continue the game ", GetScreenWidth() / 2 - 330, GetScreenHeight() / 2, 38, WHITE);
//	DrawText("Press (R) to restart the game ", GetScreenWidth() / 2 - 330, GetScreenHeight() / 2 - 100, 38, WHITE);
//	DrawText("Press (ESC) back to menu ", GetScreenWidth() / 2 - 330, GetScreenHeight() / 2 - 50, 38, WHITE);
//	DrawBack();
//	DrawCredit();
//
//	EndDrawing();
//}
//
//void ButtomPause()
//{
//
//
//}