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
	float scrollingBack = 0.0f;
	float scrollingMid = 0.0f;
	float scrollingFore = 0.0f;

	Texture2D playerTexture;
	Texture2D playerTexture2;

	Texture2D obstacleDown;
	Texture2D obstacleUp;
	
	Bird bird;
	Bird bird2;
	Obstacle obstacle = {};
	Obstacle obstacles[obstaclesQtty];
	Image icon;
	Texture2D menuBack;
	Texture2D backGround;
	Texture2D midGround;
	Texture2D foreGround;
	Texture2D sky;
	/*Parallax foreGround;
	Parallax midGround;
	Parallax backGround;*/

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
		icon = LoadImage("res/eagleOne.png");
		SetWindowIcon(icon);
		InitializeTexts();

		backGround = LoadTexture("res/Clouds.png");
		midGround = LoadTexture("res/MountainsOne.png");
		foreGround = LoadTexture("res/MountainsTwo.png");
		menuBack = LoadTexture("res/menuBackground.png");
		sky = LoadTexture("res/Sky.png");
		playerTexture = LoadTexture("res/eagleOne.png");
		playerTexture2 = LoadTexture("res/eagleTwo.png");
		obstacleUp = LoadTexture("res/ObstaculoTwo.png");
		obstacleDown = LoadTexture("res/Obstaculo.png");

		bird = CreateBird(playerTexture);
		bird2 = CreateBird(playerTexture);
		for (int i = 0; i < obstaclesQtty; i++)
		{
			obstacle = CreateObstacle(obstacleDown, obstacleUp);
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
				ScenesSwitch(menuBack);
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
		UnloadTexture(playerTexture2);
		UnloadTexture(backGround);
		UnloadTexture(midGround);
		UnloadTexture(foreGround);
		CloseWindow();
	}

	void Draw()
	{
		BeginDrawing();
		 ClearBackground(RAYWHITE);
		if (!endmatch)
		{
			if (pause)
			{
				DrawTexture(sky, 0, 0, RAYWHITE);
				drawParallax(scrollingBack, scrollingMid, scrollingFore, foreGround, midGround, backGround, pause);
				//DrawRectangleRec(GetBirdRect(bird), BLACK);
				DrawBird(bird, playerTexture2);
				for (int i = 0; i < obstaclesQtty; i++)
				{
					DrawObstacle(obstacles[i]);
				}
				DrawPause();
			}
			else
			{
				DrawTexture(sky, 0, 0, RAYWHITE);
				drawParallax(scrollingBack, scrollingMid, scrollingFore, foreGround, midGround, backGround, pause);
				//DrawRectangleRec(GetBirdRect(bird), BLACK);
				DrawBird(bird, playerTexture2);
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
				DrawBird(bird, playerTexture2);
				DrawBird(bird2, playerTexture2);
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
			if (IsKeyPressed(KEY_BACKSPACE))
			{
				pause = false;
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
						obstacle = CreateObstacle(obstacleDown, obstacleUp);
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
						obstacle = CreateObstacle(obstacleDown, obstacleUp);
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
					obstacle = CreateObstacle(obstacleDown, obstacleUp);
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
					obstacle = CreateObstacle(obstacleDown, obstacleUp);
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
						obstacle = CreateObstacle(obstacleDown, obstacleUp);
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
						obstacle = CreateObstacle(obstacleDown, obstacleUp);
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
					obstacle = CreateObstacle(obstacleDown, obstacleUp);
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
					obstacle = CreateObstacle(obstacleDown, obstacleUp);
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
					player.color = RAYWHITE;
					player.speed = 0.0f;
					collisionTimer = 1.0f;

					// Restablecer la posición del jugador
					player.pos = { static_cast<float>(GetScreenWidth() / 2) - 400, static_cast<float>(GetScreenHeight() / 2) };

					/*#ifdef _DEBUG
					cout << "vidas: " << player.vidas << endl;
					#endif*/
					// Reiniciar el tiempo desde la última colisión
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
		DrawText("Code by: Leonardo Brizuela and Ezequiel Prieto", GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 - 10, 40, WHITE);
		DrawText("Art by: Fiorella Gaston", GetScreenWidth() / 2 - 300, GetScreenHeight() / 2 + 30, 40, WHITE);
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
		DrawRectangleGradientV(GetScreenWidth() / 2 - 256, GetScreenHeight() / 2 - 192, 512, 384, BLACK, Fade(RED, 1.0f));
		DrawText("Pause", GetScreenWidth() / 2 - 140, GetScreenHeight() / 2 - 200, 100, WHITE);
		DrawText("Press (P) to continue the game ", GetScreenWidth() / 2 - 250, GetScreenHeight() / 2, 25, WHITE);
		DrawText("Press (R) to restart the game ", GetScreenWidth() / 2 - 250, GetScreenHeight() / 2 - 100, 25, WHITE);
		DrawText("Press (ESC) back to menu ", GetScreenWidth() / 2 - 250, GetScreenHeight() / 2 - 50, 25, WHITE);
		DrawBack();
	}
}