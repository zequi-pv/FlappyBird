#include<iostream>
#include "Game.h"
//#include "WindowSize.h"
#include "Bird.h"
#include "Obstacle.h"
#include "Menu.h"
#include "Parallax.h"

using namespace std;

namespace game
{
	static void Init();
	static void MainLoop();
	static void Close();
	void Update();
	void BirdCollition(Bird& player, Obstacle obs[]);
	void DrawPause();

	const int obstaclesQtty = 3;

	Texture2D playerTexture;
	Bird bird;
	Bird bird2;
	Obstacle obstacle;
	Obstacle obstacles[obstaclesQtty];
	Texture2D imageTexture;
	//Parallax foreGround;
	//Parallax midGround[2];
	//Parallax backGround;

	static bool exitWindow = false;
	static bool pause = false;
	static bool endmatch = false;
	bool isGameRunning = false;


	void RunGame()
	{
		Init();
		MainLoop();
		Close();
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
		imageTexture = LoadTexture("res/Background/sCityClose.png");
		//foreGround = InitParallax(imageTexture);
		playerTexture = LoadTexture("res/playerShip2_orange.png");
		bird = CreateBird(playerTexture);
		bird2 = CreateBird(playerTexture);
		for (int i = 0; i < obstaclesQtty; i++)
		{
			obstacle = CreateObstacle();
			obstacles[i] = obstacle;

			obstacles[i].pipeUp.pos.x = static_cast<float>(GetScreenWidth()) + 500.0f * i;
			obstacles[i].pipeDown.pos.x = static_cast<float>(GetScreenWidth()) + 500.0f * i;

		}
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
		for (int i = 0; i < obstaclesQtty; i++)
		{
			MoveObstacle(obstacles[i]);

		}
		BirdCollition(bird, obstacles);
	}

	void UpdateMultiPlayer()
	{
		UpdateBird(bird);
		UpdateBird2(bird2);
		for (int i = 0; i < obstaclesQtty; i++)
		{
			MoveObstacle(obstacles[i]);
		}
		BirdCollition(bird, obstacles);
		BirdCollition(bird2, obstacles);
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
				DrawBird(bird);
				for (int i = 0; i < obstaclesQtty; i++)
				{
					DrawObstacle(obstacles[i]);
				}
			}
		}
		EndDrawing();
	}

	void DrawMultiPlayerGame()
	{
		BeginDrawing();
		ClearBackground(WHITE);
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
				DrawBird(bird);
				DrawBird(bird2);
				for (int i = 0; i < obstaclesQtty; i++)
				{
					DrawObstacle(obstacles[i]);
				}

			}
		}
		EndDrawing();
	}

	void GameLoop()
	{
		if (!endmatch)
		{
			if (IsKeyPressed(KEY_ESCAPE))
			{
				pause = true;
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
					for (int i = 0; i < obstaclesQtty; i++)
					{
						obstacle = CreateObstacle();
						obstacles[i] = obstacle;
					}
					pause = false;
				}
				else if (IsKeyPressed(KEY_E))
				{
					menu = MenuScenes::MainMenu;
					bird = CreateBird(playerTexture);
					for (int i = 0; i < obstaclesQtty; i++)
					{
						obstacle = CreateObstacle();
						obstacles[i] = obstacle;
					}
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
				for (int i = 0; i < obstaclesQtty; i++)
				{
					obstacle = CreateObstacle();
					obstacles[i] = obstacle;

					obstacles[i].pipeUp.pos.x = static_cast<float>(GetScreenWidth()) + 500.0f * i;
					obstacles[i].pipeDown.pos.x = static_cast<float>(GetScreenWidth()) + 500.0f * i;
				}
				pause = false;
				endmatch = false;
			}
			else if (IsKeyPressed(KEY_ESCAPE))
			{
				menu = MenuScenes::MainMenu;
				bird = CreateBird(playerTexture);
				for (int i = 0; i < obstaclesQtty; i++)
				{
					obstacle = CreateObstacle();
					obstacles[i] = obstacle;

					obstacles[i].pipeUp.pos.x = static_cast<float>(GetScreenWidth()) + 500.0f * i;
					obstacles[i].pipeDown.pos.x = static_cast<float>(GetScreenWidth()) + 500.0f * i;
				}
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
					for (int i = 0; i < obstaclesQtty; i++)
					{
						obstacle = CreateObstacle();
						obstacles[i] = obstacle;
					}
					pause = false;
				}
				else if (IsKeyPressed(KEY_E))
				{
					menu = MenuScenes::MainMenu;
					bird = CreateBird(playerTexture);
					bird2 = CreateBird(playerTexture);
					for (int i = 0; i < obstaclesQtty; i++)
					{
						obstacle = CreateObstacle();
						obstacles[i] = obstacle;
					}
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
				for (int i = 0; i < obstaclesQtty; i++)
				{
					obstacle = CreateObstacle();
					obstacles[i] = obstacle;
				}
				pause = false;
				endmatch = false;
			}
			else if (IsKeyPressed(KEY_ESCAPE))
			{
				menu = MenuScenes::MainMenu;
				bird = CreateBird(playerTexture);
				bird2 = CreateBird(playerTexture);
				for (int i = 0; i < obstaclesQtty; i++)
				{
					obstacle = CreateObstacle();
					obstacles[i] = obstacle;
				}
				pause = false;
				endmatch = false;
			}
		}
		DrawMultiPlayerGame();
	}

	void BirdCollition(Bird& player, Obstacle obs[])
	{
		static float timeSinceLastCollision = 0.0f;
		static float collisionTimer = 0.0f;
		static float collisionInterval = 1.0f;
		timeSinceLastCollision += GetFrameTime();

		for (int i = 0; i < obstaclesQtty; i++)
		{
			if (timeSinceLastCollision > collisionInterval)
			{
				if (!obs[i].isHit && CheckCollisionRecs(GetBirdRect(player), GetRecObstacleUp(obs[i])) || !obs[i].isHit && CheckCollisionRecs(GetBirdRect(player), GetRecObstacleDown(obs[i])) || player.pos.y > GetScreenHeight())
				{
					obs[i].isHit = true;
					player.vidas -= 1;
					player.color = BLUE;
					player.speed = 0.0f;
					collisionTimer = 1.0f;

					// Restablecer la posici�n del jugador
					player.pos = { static_cast<float>(GetScreenWidth() / 2) - 500, static_cast<float>(GetScreenHeight() / 2) };

					/*#ifdef _DEBUG
					cout << "vidas: " << player.vidas << endl;
					#endif*/
					// Reiniciar el tiempo desde la �ltima colisi�n
					timeSinceLastCollision = 0.0f;

					if (player.vidas <= 0)
					{
						endmatch = true;
					}
				}
			}
			if (obs[i].isHit)
			{
				collisionTimer -= GetFrameTime();

				if (collisionTimer <= 0.0f)
				{
					obs[i].isHit = false;
					player.color = RED;
				}

			}
			timeSinceLastCollision += GetFrameTime();
		}


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
}