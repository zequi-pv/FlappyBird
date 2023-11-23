#include<iostream>
#include "Game.h"
//#include "WindowSize.h"
#include "Bird.h"
#include "Obstacle.h"
#include "Menu.h"
#include "Parallax.h"

using namespace std;

static void Init();
static void MainLoop();
static void Close();
void Update();
void BirdCollition(Bird& bird, Obstacle& obstacle);
void DrawPause();

Texture2D playerTexture;
Bird bird;
Bird bird2;
Obstacle obstacle;
Obstacle obstacle2;
Obstacle obstacle3;
Obstacle obstacle4;
Obstacle obstacle5;
Obstacle obstacle6;
Texture2D imageTexture;
//Parallax foreGround;
//Parallax midGround[2];
//Parallax backGround;

static bool exitWindow = false;
static bool pause = false;
static bool endmatch = false;
bool isGameRunning = false;

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
	const int screenWidth = 1024;
	const int screenHeight = 768;

	InitWindow(static_cast<int>(screenWidth), static_cast<int>(screenHeight), "ASTEROIDS");
	SetExitKey(KEY_NULL);
	InitializeTexts();
	
	 //backGround = LoadTexture("res/Background/sCitySky.png");
	//Texture2D midGround = LoadTexture("res/Background/sCityMid.png");
	imageTexture= LoadTexture("res/Background/sCityClose.png");
	//foreGround = InitParallax(imageTexture);
	playerTexture = LoadTexture("res/playerShip2_orange.png");
	bird = CreateBird(playerTexture);
	bird2 = CreateBird(playerTexture);
	obstacle = CreateObstacle(static_cast<float>(GetScreenWidth() - 100));
	obstacle2 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 100));
	obstacle3 = CreateObstacle(static_cast<float>(GetScreenWidth() - 800));
	obstacle4 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 800));;
	obstacle5 = CreateObstacle(static_cast<float>(GetScreenWidth() - 1500));;
	obstacle6 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 1500));;
}

void MainLoop()
{
	while (!exitWindow)
	{
		while (!WindowShouldClose() && !isGameRunning)
		{
			ScenesSwitch();
			exitWindow = true;
		}
	}
}

void Update()
{
	UpdateBird(bird);
	UpdateObstacle(obstacle);
	UpdateObstacle2(obstacle2);
	UpdateObstacle(obstacle3);
	UpdateObstacle2(obstacle4);
	UpdateObstacle(obstacle5);
	UpdateObstacle2(obstacle6);
	BirdCollition(bird,obstacle);
	BirdCollition(bird, obstacle2);
	BirdCollition(bird, obstacle3);
	BirdCollition(bird, obstacle4);
	BirdCollition(bird, obstacle5);
	BirdCollition(bird, obstacle6);
}

void UpdateMultiPlayer()
{
	UpdateBird(bird);
	UpdateBird2(bird2);
	UpdateObstacle(obstacle);
	UpdateObstacle2(obstacle2);
	BirdCollition(bird, obstacle);
	BirdCollition(bird2, obstacle);
	BirdCollition(bird, obstacle2);
	BirdCollition(bird2, obstacle2);
}

void Close()
{
	UnloadTexture(playerTexture);
	UnloadTexture(imageTexture);
	///UnloadTexture(backGround);0
	/*UnloadTexture(playerTexture);*/
	CloseWindow();
}

void Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);
	//DrawRectangle(0, 0, 5, GetScreenHeight(), Fade(GREEN, 1.0f));
	//DrawRectangle(GetScreenWidth() - 5, 0, 5, GetScreenHeight(), Fade(WHITE, 1.0f));
	if(!endmatch)
	{
		if (pause)
		{
			DrawPause();
		}
		else
		{
			//DrawParallax(foreGround);
			DrawRectangleRec(GetBirdRect(bird), BLACK);
			DrawRectangleRec(GetRecObstacle(obstacle), GREEN);
			DrawRectangleRec(GetRecObstacle(obstacle2), GREEN);
			DrawRectangleRec(GetRecObstacle(obstacle3), GREEN);
			DrawRectangleRec(GetRecObstacle(obstacle4), GREEN);
			DrawRectangleRec(GetRecObstacle(obstacle5), GREEN);
			DrawRectangleRec(GetRecObstacle(obstacle6), GREEN);
			DrawBird(bird);
			DrawObstacle(obstacle);
			DrawObstacle(obstacle2);
			DrawObstacle(obstacle3);
			DrawObstacle(obstacle4);
			DrawObstacle(obstacle5);
			DrawObstacle(obstacle6);
			
		}
	}
	EndDrawing();
}

void DrawMultiPlayerGame()
{
	BeginDrawing();
	ClearBackground(WHITE);
	//DrawRectangle(0, 0, 5, GetScreenHeight(), Fade(GREEN, 1.0f));
	//DrawRectangle(GetScreenWidth() - 5, 0, 5, GetScreenHeight(), Fade(WHITE, 1.0f));
	if (!endmatch)
	{
		if (pause)
		{
			DrawPause();
		}
		else
		{
			//DrawParallax(foreGround);
			DrawRectangleRec(GetBirdRect(bird), BLACK);
			DrawRectangleRec(GetBirdRect(bird2), BLACK);
			DrawRectangleRec(GetRecObstacle(obstacle), GREEN);
			DrawRectangleRec(GetRecObstacle(obstacle2), GREEN);
			DrawRectangleRec(GetRecObstacle(obstacle3), GREEN);
			DrawRectangleRec(GetRecObstacle(obstacle4), GREEN);
			DrawRectangleRec(GetRecObstacle(obstacle5), GREEN);
			DrawRectangleRec(GetRecObstacle(obstacle6), GREEN);
			DrawBird(bird);
			DrawBird(bird2);
			DrawObstacle(obstacle);
			DrawObstacle(obstacle2);
			DrawObstacle(obstacle3);
			DrawObstacle(obstacle4);
			DrawObstacle(obstacle5);
			DrawObstacle(obstacle6);
			
		}
	}
	EndDrawing();
}

void GameLoop()
{
	//cout << "endmatch " << endmatch<<endl;
	if (!endmatch)
	{
		if (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_P))
		{
			pause = !pause;
			cout << "pause" << endl;
			cout << pause << endl;
			
		}
		if (!pause)
		{
			Update();
		}
		else
		{
			DrawPause();

			if (IsKeyPressed(KEY_R))
			{
				bird = CreateBird(playerTexture);
				obstacle = CreateObstacle(static_cast<float>(GetScreenWidth() - 100));
				obstacle2 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 100));
				obstacle3 = CreateObstacle(static_cast<float>(GetScreenWidth() - 300));
				obstacle4 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 300));;
				obstacle5 = CreateObstacle(static_cast<float>(GetScreenWidth() - 500));;
				obstacle6 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 500));;
				pause = false;
			}
			else if (IsKeyPressed(KEY_E))
			{
				menu = MenuScenes::MainMenu;
				bird = CreateBird(playerTexture);
				obstacle = CreateObstacle(static_cast<float>(GetScreenWidth() - 100));
				obstacle2 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 100));
				obstacle3 = CreateObstacle(static_cast<float>(GetScreenWidth() - 300));
				obstacle4 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 300));;
				obstacle5 = CreateObstacle(static_cast<float>(GetScreenWidth() - 500));;
				obstacle6 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 500));;
				pause = false;
			}
		}
		
	}else
	{
		DrawRectangleGradientV(GetScreenWidth() / 2 - 512, GetScreenHeight() / 2 - 384, 1024, 768, BLACK, Fade(RED, 1.0f));
		DrawText(TextFormat("You Lose"), 50, 200, 55, WHITE);
		DrawText(TextFormat("Press R to play again or Esc to Exit"), 50, 250, 35, WHITE);

		if (IsKeyPressed(KEY_R))
		{
			bird = CreateBird(playerTexture);
			obstacle = CreateObstacle(static_cast<float>(GetScreenWidth() - 100));
			obstacle2 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 100));
			obstacle3 = CreateObstacle(static_cast<float>(GetScreenWidth() - 300));
			obstacle4 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 300));;
			obstacle5 = CreateObstacle(static_cast<float>(GetScreenWidth() - 500));;
			obstacle6 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 500));;
			pause = false;
			endmatch = false;
		}
		else if (IsKeyPressed(KEY_ESCAPE))
		{
			menu = MenuScenes::MainMenu;
			bird = CreateBird(playerTexture);
			obstacle = CreateObstacle(static_cast<float>(GetScreenWidth() - 100));
			obstacle2 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 100));
			obstacle3 = CreateObstacle(static_cast<float>(GetScreenWidth() - 300));
			obstacle4 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 300));;
			obstacle5 = CreateObstacle(static_cast<float>(GetScreenWidth() - 500));;
			obstacle6 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 500));;
			pause = false;
			endmatch = false;
		}
	}
	Draw();
}

void GameLoopMultiPlayer()
{
	//cout << "endmatch " << endmatch<<endl;
	if (!endmatch)
	{
		if (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_P))
		{
			pause = !pause;
			/*cout << "pause" << endl;
			cout << pause << endl;*/

		}
		if (!pause)
		{
			UpdateMultiPlayer();
		}
		else
		{
			DrawPause();

			if (IsKeyPressed(KEY_R))
			{
				bird = CreateBird(playerTexture);
				bird2 = CreateBird(playerTexture);
				obstacle = CreateObstacle(static_cast<float>(GetScreenWidth() - 100));
				obstacle2 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 100));
				obstacle3 = CreateObstacle(static_cast<float>(GetScreenWidth() - 300));
				obstacle4 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 300));;
				obstacle5 = CreateObstacle(static_cast<float>(GetScreenWidth() - 500));;
				obstacle6 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 500));;
				pause = false;
			}
			else if (IsKeyPressed(KEY_E))
			{
				menu = MenuScenes::MainMenu;
				bird = CreateBird(playerTexture);
				bird2 = CreateBird(playerTexture);
				obstacle = CreateObstacle(static_cast<float>(GetScreenWidth() - 100));
				obstacle2 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 100));
				obstacle3 = CreateObstacle(static_cast<float>(GetScreenWidth() - 300));
				obstacle4 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 300));;
				obstacle5 = CreateObstacle(static_cast<float>(GetScreenWidth() - 500));;
				obstacle6 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 500));;
				pause = false;
			}
		}

	}
	else
	{
		DrawRectangleGradientV(GetScreenWidth() / 2 - 512, GetScreenHeight() / 2 - 384, 1024, 768, BLACK, Fade(RED, 1.0f));
		DrawText(TextFormat("You Lose"), 50, 200, 55, WHITE);
		DrawText(TextFormat("Press R to play again or Esc to Exit"), 50, 250, 35, WHITE);

		if (IsKeyPressed(KEY_R))
		{
			bird = CreateBird(playerTexture);
			bird2 = CreateBird(playerTexture);
			obstacle = CreateObstacle(static_cast<float>(GetScreenWidth() - 100));
			obstacle2 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 100));
			obstacle3 = CreateObstacle(static_cast<float>(GetScreenWidth() - 300));
			obstacle4 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 300));;
			obstacle5 = CreateObstacle(static_cast<float>(GetScreenWidth() - 500));;
			obstacle6 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 500));;
			pause = false;
			endmatch = false;
		}
		else if (IsKeyPressed(KEY_ESCAPE))
		{
			menu = MenuScenes::MainMenu;
			bird = CreateBird(playerTexture);
			bird2 = CreateBird(playerTexture);
			obstacle = CreateObstacle(static_cast<float>(GetScreenWidth() - 100));
			obstacle2 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 100));
			obstacle3 = CreateObstacle(static_cast<float>(GetScreenWidth() - 300));
			obstacle4 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 300));;
			obstacle5 = CreateObstacle(static_cast<float>(GetScreenWidth() - 500));;
			obstacle6 = CreateObstacle2(static_cast<float>(GetScreenWidth() - 500));;
			pause = false;
			endmatch = false;
		}
	}
	DrawMultiPlayerGame();
}

void BirdCollition(Bird& player, Obstacle& obs)
{
	static float timeSinceLastCollision = 0.0f;
	static float collisionTimer = 0.0f;
	static float collisionInterval = 1.0f;
	timeSinceLastCollision += GetFrameTime();

	if (timeSinceLastCollision > collisionInterval)
	{
		if (!obs.hit && CheckCollisionRecs(GetBirdRect(player), GetRecObstacle(obstacle))||player.pos.y>GetScreenHeight())
		{
			obs.hit = true;
			player.vidas -= 1;
			player.color = BLUE;
			player.speed = 0.0f;
			collisionTimer = 1.0f;

			// Restablecer la posición del jugador
			player.pos = { static_cast<float>(GetScreenWidth() / 2) - 500, static_cast<float>(GetScreenHeight() / 2) };

            #ifdef _DEBUG
			cout << "vidas: " << player.vidas << endl;
            #endif
			// Reiniciar el tiempo desde la última colisión
			timeSinceLastCollision = 0.0f;

			if (player.vidas<=0)
			{
				endmatch = true;
			}
		}
	}
	if(obs.hit==true)
	{
		collisionTimer -= GetFrameTime();

		if (collisionTimer<=0.0f)
		{
			obs.hit = false;
			player.color = RED;
		}
		
	}
	timeSinceLastCollision += GetFrameTime();
}

void WindowInstructions()
{
	BeginDrawing();

	DrawRectangleGradientV(GetScreenWidth() / 2 - 512, GetScreenHeight() / 2 - 384, 1024, 768, BLACK, Fade(RED, 1.0f));
	DrawText("Use Up/Down to move rigth paddles", GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 - 10, 40, WHITE);
	DrawText("Use W/S to move left paddles", GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 - 100, 40, WHITE);
	//DrawText("(ESC) Back", GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 + 200, 40, WHITE);
	DrawBack();
	CheckBack();
	EndDrawing();
	backMenu();
}

void UpdateMenu()
{
	CheckSinglePlayer();
	CheckMultiPlayer();
	CheckInstructions();
	CheckCredits();
	CheckBack();
	CheckQuit();
}

void CreditsWindow()
{
	BeginDrawing();

	DrawRectangleGradientV(GetScreenWidth() / 2 - 512, GetScreenHeight() / 2 - 384, 1024, 768, BLACK, Fade(RED, 1.0f));
	DrawText("Code by: Leonardo Brizuela", GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 - 10, 40, WHITE);
	//DrawText("(ESC) Back", GetScreenWidth() / 2 - 350, GetScreenHeight() / 2 + 200, 40, WHITE);
	DrawBack();
	CheckBack();
	EndDrawing();
	backMenu();
}

void backMenu()
{
	if (IsKeyPressed(KEY_ESCAPE))
	{
		menu = MenuScenes::MainMenu;
	}
}

void DrawPause()
{
	BeginDrawing();

	DrawRectangleGradientV(GetScreenWidth() / 2 - 512, GetScreenHeight() / 2 - 384, 1024, 768, BLACK, Fade(RED, 1.0f));
	DrawText("Pause", GetScreenWidth() / 2 - 140, GetScreenHeight() / 2 - 250, 100, WHITE);
	DrawText("Press (P) to continue the game ", GetScreenWidth() / 2 - 330, GetScreenHeight() / 2, 38, WHITE);
	DrawText("Press (R) to restart the game ", GetScreenWidth() / 2 - 330, GetScreenHeight() / 2 - 100, 38, WHITE);
	DrawText("Press (ESC) back to menu ", GetScreenWidth() / 2 - 330, GetScreenHeight() / 2 - 50, 38, WHITE);
	DrawBack();
	

	EndDrawing();
}