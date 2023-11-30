#include<iostream>
#include "Game.h"
//#include "WindowSize.h"
#include "Bird.h"
#include "Obstacle.h"
#include "Menu.h"
#include "Parallax.h"
#include "Button.h"
#include "Utils.h"

using namespace std;

namespace game
{
	static void Init();
	static void MainLoop();
	static void Close();
	void Update();
	void BirdCollition(Bird& player, Obstacle obs[]);
	void givePoints(Bird& player, Obstacle obs[]);
	void givePointsMulti(Bird& player, Bird& player2, Obstacle obs[]);
	void resetBird(Bird& player, Obstacle obs[]);
	void resetGame(Bird& player, Obstacle obs[], bool& paused, bool& gameOver);
	void resetMusic(Music& music);
	void drawButton(Vector2 mouse, Button& button);
	void DrawPause(Vector2 mouse);
	void DrawGameOver(Vector2 mouse);
	void DrawGameOverMulti(Vector2 mouse);

	const int obstaclesQtty = 3;
	float scrollingBack = 0.0f;
	float scrollingMid = 0.0f;
	float scrollingFore = 0.0f;

	Vector2 buttonSize = {200, 43};

	Button playSingleB, playMultiB, rulesB, creditsB, exitB, backB, continueB, pauseB;

	Sound jumpS, obshitS, gameoverS, optionS, groundhitS;

	Texture2D lives;
	Texture2D score;

	Texture2D playerTexture;
	Texture2D playerTexture2;

	Texture2D obstacleDown;
	Texture2D obstacleUp;

	Texture2D playButtonN, 
		playButtonS, 
		backButtonN, 
		backButtonS, 
		playMultiBN, 
		playMultiBS, 
		rulesButtonN,
		rulesButtonS,
		creditsButtonN,
		creditsButtonS,
		exitButtonN,
		exitButtonS,
		continueButtonN,
		continueButtonS,
		pauseButtonN,
		pauseButtonS;
	
	Music menuMusic, gameplayMusic;

	Bird bird;
	Bird bird2;
	Obstacle obstacle = {};
	Obstacle obstacles[obstaclesQtty];

	Image icon;
	Texture2D menuBack,
			titleMenu,
			gameoverTitle,
			ScoreTitle,
			LivesTitle;

	Texture2D rules, credits;

	Texture2D backGround, midGround, foreGround, sky;
	

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

		InitWindow(static_cast<int>(screenWidth), static_cast<int>(screenHeight), "FLAPPY BIRD - Prieto");
		InitAudioDevice();
		SetExitKey(KEY_NULL);
		icon = LoadImage("res/eagleOne.png");
		SetWindowIcon(icon);

		jumpS = LoadSound("res/Sounds/jump.wav");
		obshitS = LoadSound("res/Sounds/obsHit.wav");
		gameoverS = LoadSound("res/Sounds/gameOver.wav");
		optionS = LoadSound("res/Sounds/Points.wav");
		groundhitS = LoadSound("res/Sounds/groundHit.wav");

		titleMenu = LoadTexture("res/Title.png");
		gameoverTitle = LoadTexture("res/gameOver.png");
		ScoreTitle = LoadTexture("res/Score.png");
		LivesTitle = LoadTexture("res/Lives.png");

		backButtonN = LoadTexture("res/Buttons/Back.png");
		backButtonS = LoadTexture("res/Buttons/Selected/Back.png");
		
		playButtonN = LoadTexture("res/Buttons/Singleplayer.png");
		playButtonS = LoadTexture("res/Buttons/Selected/Singleplayer.png");

		playMultiBN = LoadTexture("res/Buttons/Multiplayer.png");
		playMultiBS = LoadTexture("res/Buttons/Selected/Multiplayer.png");

		rulesButtonN = LoadTexture("res/Buttons/Rules.png");
		rulesButtonS = LoadTexture("res/Buttons/Selected/Rules.png");

		creditsButtonN = LoadTexture("res/Buttons/Credits.png");
		creditsButtonS = LoadTexture("res/Buttons/Selected/Credits.png");

		exitButtonN = LoadTexture("res/Buttons/Exit.png");
		exitButtonS = LoadTexture("res/Buttons/Selected/Exit.png");

		continueButtonN = LoadTexture("res/Buttons/Continue.png");
		continueButtonS = LoadTexture("res/Buttons/Selected/Continue.png");

		pauseButtonN = LoadTexture("res/Buttons/Pause.png");
		pauseButtonS = LoadTexture("res/Buttons/PauseV2.png");

		playSingleB = initButtonTex(buttonSize, playButtonN, playButtonS);
		playMultiB = initButtonTex(buttonSize, playMultiBN, playMultiBS);
		rulesB = initButtonTex(buttonSize, rulesButtonN, rulesButtonS);
		creditsB = initButtonTex(buttonSize, creditsButtonN, creditsButtonS);
		exitB = initButtonTex(buttonSize, exitButtonN, exitButtonS);
		backB = initButtonTex(buttonSize, backButtonN, backButtonS);
		continueB = initButtonTex(buttonSize, continueButtonN, continueButtonS);
		pauseB = initButtonTex(buttonSize, pauseButtonN, pauseButtonS);

		backGround = LoadTexture("res/Clouds.png");
		midGround = LoadTexture("res/v2/mountainsOne.png");
		foreGround = LoadTexture("res/MountainsTwo.png");
		menuBack = LoadTexture("res/menuBackground.png");
		sky = LoadTexture("res/Sky.png");

		rules = LoadTexture("res/rules.png");
		credits = LoadTexture("res/credits.png");

		playerTexture = LoadTexture("res/eagleOne.png");
		playerTexture2 = LoadTexture("res/eagleTwo.png");
		obstacleUp = LoadTexture("res/ObstaculoTwo.png");
		obstacleDown = LoadTexture("res/Obstaculo.png");

		menuMusic = LoadMusicStream("res/sounds/menuMusic.wav");
		gameplayMusic = LoadMusicStream("res/sounds/gameplayMusic.wav");

		PlayMusicStream(gameplayMusic);
		SetMusicVolume(gameplayMusic, 0.5f);

		PlayMusicStream(menuMusic);
		SetMusicVolume(menuMusic, 0.5f);

		bird = CreateBird(playerTexture);
		bird2 = CreateBird(playerTexture);
		bird2.pos.x = bird.pos.x + 200.0f;
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
				ScenesSwitch();
				exitWindow = true;
			}
		}
	}

	void Update()
	{
		UpdateMusicStream(gameplayMusic);
		UpdateBird(bird, jumpS);
		for (int i = 0; i < obstaclesQtty; i++)
		{
			MoveObstacle(obstacles[i]);

		}
		BirdCollition(bird, obstacles);
		givePoints(bird, obstacles);
	}

	void UpdateMultiPlayer()
	{
		UpdateMusicStream(gameplayMusic);
		UpdateBird(bird, jumpS);
		UpdateBird2(bird2, jumpS);
		for (int i = 0; i < obstaclesQtty; i++)
		{
			MoveObstacle(obstacles[i]);
		}
		BirdCollition(bird, obstacles);
		BirdCollition(bird2, obstacles);
		bird2.pos.x = bird.pos.x + 200.0f;
		givePointsMulti(bird, bird2, obstacles);
	}

	void Close()
	{
		UnloadTexture(playerTexture);
		UnloadTexture(playerTexture2);
		UnloadTexture(backGround);
		UnloadTexture(midGround);
		UnloadTexture(foreGround);
		UnloadTexture(sky);
		UnloadTexture(playButtonN);
		UnloadTexture(playButtonS);
		UnloadTexture(backButtonN);
		UnloadTexture(backButtonS);
		UnloadTexture(playMultiBN);
		UnloadTexture(playMultiBS);
		UnloadTexture(rulesButtonN);
		UnloadTexture(rulesButtonS);
		UnloadTexture(creditsButtonN);
		UnloadTexture(creditsButtonS);
		UnloadTexture(exitButtonN);
		UnloadTexture(exitButtonS);
		UnloadTexture(pauseButtonN);
		UnloadTexture(pauseButtonS);
		UnloadTexture(continueButtonN);
		UnloadTexture(continueButtonS);
		UnloadTexture(menuBack);
		UnloadTexture(titleMenu);
		UnloadTexture(gameoverTitle);
		UnloadTexture(ScoreTitle);
		UnloadTexture(LivesTitle);
		UnloadTexture(lives);
		UnloadTexture(score);
		UnloadTexture(rules);
		UnloadTexture(credits);
		UnloadSound(jumpS);
		UnloadSound(obshitS);
		UnloadSound(gameoverS);
		UnloadSound(optionS);
		UnloadSound(groundhitS);
		UnloadMusicStream(menuMusic);
		UpdateMusicStream(gameplayMusic);
		UnloadImage(icon);
		CloseWindow();
	}

	void Draw(Vector2 mouse)
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		if (!endmatch)
		{
			if (pause)
			{
				DrawTexture(sky, 0, 0, RAYWHITE);
				drawParallax(scrollingBack, scrollingMid, scrollingFore, foreGround, midGround, backGround, pause, endmatch);
				DrawBird(bird, playerTexture2);
				for (int i = 0; i < obstaclesQtty; i++)
				{
					DrawObstacle(obstacles[i]);
				}
				DrawPause(mouse);
				pauseB.pos.x = static_cast<float>(GetScreenWidth() - 70);
				pauseB.pos.y = static_cast<float>(20);
				drawButton(mouse, pauseB);
				DrawTexture(ScoreTitle, 10, 50, RAYWHITE);
				DrawText(TextFormat("%i", bird.score), 150, 50, 40, BROWN);

				DrawTexture(LivesTitle, 10, 100, RAYWHITE);
				DrawText(TextFormat("%i", bird.lives), 150, 100, 40, BROWN);
			}
			else
			{
				DrawTexture(sky, 0, 0, RAYWHITE);
				drawParallax(scrollingBack, scrollingMid, scrollingFore, foreGround, midGround, backGround, pause, endmatch);
				DrawBird(bird, playerTexture2);
				
				for (int i = 0; i < obstaclesQtty; i++)
				{
					DrawObstacle(obstacles[i]);
				}

				pauseB.pos.x = static_cast<float>(GetScreenWidth() - 70);
				pauseB.pos.y = static_cast<float>(20);
				drawButton(mouse, pauseB);
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && pauseB.isSelected == true)
				{
					PlaySound(optionS);
					pause = true;
				}

				DrawTexture(ScoreTitle, 10, 50, RAYWHITE);
				DrawText(TextFormat("%i", bird.score), 150, 50, 40, BROWN);

				DrawTexture(LivesTitle, 10, 100, RAYWHITE);
				DrawText(TextFormat("%i", bird.lives), 150, 100, 40, BROWN);
			}
		}
		EndDrawing();
	}

	void DrawMultiPlayerGame(Vector2 mouse)
	{
		BeginDrawing();
		ClearBackground(WHITE);
		if (!endmatch)
		{
			if (pause)
			{
				DrawTexture(sky, 0, 0, RAYWHITE);
				drawParallax(scrollingBack, scrollingMid, scrollingFore, foreGround, midGround, backGround, pause, endmatch);
				DrawBird(bird, playerTexture2);
				DrawBird(bird2, playerTexture2);
				for (int i = 0; i < obstaclesQtty; i++)
				{
					DrawObstacle(obstacles[i]);
				}
				DrawPause(mouse);
				pauseB.pos.x = static_cast<float>(GetScreenWidth() - 70);
				pauseB.pos.y = static_cast<float>(20);
				drawButton(mouse, pauseB);
				DrawTexture(ScoreTitle, 10, 50, RAYWHITE);
				DrawText(TextFormat("%i", bird.score), 150, 50, 40, BROWN);

				DrawTexture(LivesTitle, 10, 100, RAYWHITE);
				DrawText(TextFormat("%i", bird.lives), 150, 100, 40, BROWN);
			}
			else
			{
				DrawTexture(sky, 0, 0, RAYWHITE);
				drawParallax(scrollingBack, scrollingMid, scrollingFore, foreGround, midGround, backGround, pause, endmatch);
				DrawBird(bird, playerTexture2);
				DrawBird(bird2, playerTexture2);
				for (int i = 0; i < obstaclesQtty; i++)
				{
					DrawObstacle(obstacles[i]);
				}
				pauseB.pos.x = static_cast<float>(GetScreenWidth() - 70);
				pauseB.pos.y = static_cast<float>(20);
				drawButton(mouse, pauseB);
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && pauseB.isSelected == true)
				{
					PlaySound(optionS);
					pause = true;
				}

				DrawTexture(ScoreTitle, 10, 50, RAYWHITE);
				DrawText(TextFormat("%i", bird.score), 150, 50, 40, BROWN);

				DrawTexture(LivesTitle, 10, 100, RAYWHITE);
				DrawText(TextFormat("%i", bird.lives), 150, 100, 40, BROWN);

				DrawTexture(ScoreTitle, GetScreenWidth() - 250, 50, RAYWHITE);
				DrawText(TextFormat("%i", bird2.score), GetScreenWidth() - 100, 50, 40, BROWN);

				DrawTexture(LivesTitle, GetScreenWidth() - 250, 100, RAYWHITE);
				DrawText(TextFormat("%i", bird2.lives), GetScreenWidth() - 100, 100, 40, BROWN);
			}
		}
		EndDrawing();
	}

	void GameLoop(Vector2 mouse)
	{
		if (!endmatch)
		{
			if (!pause)
			{
				Update();
			}
			else
			{
				DrawPause(mouse);
			}
		}
		else
		{
			DrawTexture(sky, 0, 0, RAYWHITE);
			drawParallax(scrollingBack, scrollingMid, scrollingFore, foreGround, midGround, backGround, pause, endmatch);
			DrawBird(bird, playerTexture2);
			for (int i = 0; i < obstaclesQtty; i++)
			{
				DrawObstacle(obstacles[i]);
			}
			DrawGameOver(mouse);
		}
		Draw(mouse);
	}

	void GameLoopMultiPlayer(Vector2 mouse)
	{
		if (!endmatch)
		{
			if (!pause)
			{
				UpdateMultiPlayer();
			}
			else
			{
				DrawPause(mouse);
			}

		}
		else
		{
			DrawTexture(sky, 0, 0, RAYWHITE);
			drawParallax(scrollingBack, scrollingMid, scrollingFore, foreGround, midGround, backGround, pause, endmatch);
			DrawBird(bird, playerTexture2);
			DrawBird(bird2, playerTexture2);
			for (int i = 0; i < obstaclesQtty; i++)
			{
				DrawObstacle(obstacles[i]);
			}
			DrawGameOverMulti(mouse);
			
		}
		DrawMultiPlayerGame(mouse);
	}

	void givePoints(Bird& player, Obstacle obs[])
	{
		for (int i = 0; i < obstaclesQtty; i++)
		{
			if (player.pos.x > obs[i].pipeDown.pos.x + (obs[i].pipeDown.size.x / 2)
				&& player.pos.x > obs[i].pipeUp.pos.x + (obs[i].pipeUp.size.x / 2)
				&& !obs[i].isHit)
			{
				player.score += obs[i].pointsToGive;
				obs[i].givenPoints = true;
				
				if (obs[i].givenPoints)
				{
					obs[i].pointsToGive = 0;
					
				}
			}
		}
	}

	void givePointsMulti(Bird& player, Bird& player2, Obstacle obs[])
	{
		for (int i = 0; i < obstaclesQtty; i++)
		{
			if (player.pos.x > obs[i].pipeDown.pos.x + (obs[i].pipeDown.size.x / 2)
				&& player.pos.x > obs[i].pipeUp.pos.x + (obs[i].pipeUp.size.x / 2)
				&& !obs[i].isHit)
			{
				player.score += obs[i].pointsToGive;
				obs[i].givenPoints = true;

				if (obs[i].givenPoints)
				{
					obs[i].pointsToGive = 0;

				}
			}

			if (player2.pos.x > obs[i].pipeDown.pos.x + (obs[i].pipeDown.size.x / 2)
				&& player2.pos.x > obs[i].pipeUp.pos.x + (obs[i].pipeUp.size.x / 2)
				&& !obs[i].isHit)
			{
				player2.score += obs[i].pointsToGiveP2;
				obs[i].givenPointsP2 = true;

				if (obs[i].givenPointsP2)
				{
					obs[i].pointsToGiveP2 = 0;

				}
			}
		}
	}

	void resetGame(Bird& player, Obstacle obs[], bool& paused, bool& gameOver)
	{
		player = CreateBird(playerTexture);

		for (int i = 0; i < obstaclesQtty; i++)
		{
			obstacle = CreateObstacle(obstacleDown, obstacleUp);
			obs[i] = obstacle;

			obs[i].pipeUp.pos.x = static_cast<float>(GetScreenWidth()) + 500.0f * i;
			obs[i].pipeDown.pos.x = static_cast<float>(GetScreenWidth()) + 500.0f * i;

		}

		paused = false;
		gameOver = false;
	}

	void resetBird(Bird& player, Obstacle obs[])
	{
		player.pos = { static_cast<float>(GetScreenWidth() / 2) - 400, static_cast<float> (GetScreenHeight() / 2) };

		for (int i = 0; i < obstaclesQtty; i++)
		{
			obstacle = CreateObstacle(obstacleDown, obstacleUp);
			obs[i] = obstacle;

			obs[i].pipeUp.pos.x = static_cast<float>(GetScreenWidth()) + 500.0f * i;
			obs[i].pipeDown.pos.x = static_cast<float>(GetScreenWidth()) + 500.0f * i;

		}
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
				if (!obs[i].isHit && CheckCollisionRecs(GetBirdRect(player), GetRecObstacleUp(obs[i])) || !obs[i].isHit && CheckCollisionRecs(GetBirdRect(player), GetRecObstacleDown(obs[i])))
				{
					obs[i].isHit = true;
					player.lives -= 1;
					player.color = RAYWHITE;
					player.speed = 0.0f;
					collisionTimer = 1.0f;

					PlaySound(obshitS);
					resetBird(player, obs);
					
					timeSinceLastCollision = 0.0f;

					if (player.lives <= 0)
					{
						endmatch = true;
					}
				}
				if (player.pos.y > GetScreenHeight())
				{
					obs[i].isHit = true;
					player.lives -= 1;
					player.color = RAYWHITE;
					player.speed = 0.0f;
					collisionTimer = 1.0f;

					PlaySound(groundhitS);
					resetBird(player, obs);

					timeSinceLastCollision = 0.0f;

					if (player.lives <= 0)
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

	void WindowInstructions(Vector2 mouse)
	{
		backB.pos.x = 20.0f;
		backB.pos.y = static_cast<float>(GetScreenHeight() - 75);
		UpdateMusicStream(menuMusic);
		BeginDrawing();
		DrawTexture(menuBack, 0, 0, RAYWHITE);
		DrawTexture(rules, 5, 10, RAYWHITE);
		DrawTexture(backB.button, static_cast<int>(backB.pos.x), static_cast<int>(backB.pos.y), RAYWHITE);
		drawButton(mouse, backB);

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && backB.isSelected == true)
		{
			PlaySound(optionS);
			menu = MenuScenes::MainMenu;
		}

		EndDrawing();
		backMenu();
	}

	void DrawGameOver(Vector2 mouse) 
	{
		DrawTexture(gameoverTitle, (GetScreenWidth() / 2) - (gameoverTitle.width / 2), 200, RAYWHITE);
		DrawTexture(ScoreTitle, (GetScreenWidth() / 2) - 150, 300, RAYWHITE);
		DrawText(TextFormat("%i", bird.score), (GetScreenWidth() / 2) + 10, 300, 40, BROWN);
		backB.pos.x = (GetScreenWidth() / 2) - 200.0f;
		backB.pos.y = static_cast<float>(GetScreenHeight() / 2);
		DrawTexture(backB.button, static_cast<int>(backB.pos.x), static_cast<int>(backB.pos.y), RAYWHITE);
		drawButton(mouse, backB);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && backB.isSelected == true)
		{
			PlaySound(optionS);
			menu = MenuScenes::MainMenu;
			resetMusic(gameplayMusic);
			resetMusic(menuMusic);
			resetGame(bird, obstacles, pause, endmatch);
		}

		continueB.pos.x = static_cast<float>((GetScreenWidth() / 2));
		continueB.pos.y = static_cast<float>(GetScreenHeight() / 2);
		DrawTexture(continueB.button, static_cast<int>(continueB.pos.x), static_cast<int>(continueB.pos.y), RAYWHITE);
		drawButton(mouse, continueB);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && continueB.isSelected == true)
		{
			PlaySound(optionS);
			resetMusic(gameplayMusic);
			resetGame(bird, obstacles, pause, endmatch);
		}
	}

	void DrawGameOverMulti(Vector2 mouse)
	{
		DrawTexture(gameoverTitle, (GetScreenWidth() / 2) - (gameoverTitle.width / 2), 200, RAYWHITE);
		DrawTexture(ScoreTitle, (GetScreenWidth() / 2) - 150, 300, RAYWHITE);
		DrawText(TextFormat("%i", bird.score), (GetScreenWidth() / 2) + 10, 300, 40, BROWN);
		DrawTexture(ScoreTitle, (GetScreenWidth() / 2) - 150, 350, RAYWHITE);
		DrawText(TextFormat("%i", bird2.score), (GetScreenWidth() / 2) + 10, 350, 40, BROWN);
		backB.pos.x = (GetScreenWidth() / 2) - 200.0f;
		backB.pos.y = static_cast<float>(GetScreenHeight() / 2);
		DrawTexture(backB.button, static_cast<int>(backB.pos.x), static_cast<int>(backB.pos.y), RAYWHITE);
		drawButton(mouse, backB);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && backB.isSelected == true)
		{
			PlaySound(optionS);
			menu = MenuScenes::MainMenu;
			resetMusic(gameplayMusic);
			resetMusic(menuMusic);
			bird2 = CreateBird(playerTexture);
			resetGame(bird, obstacles, pause, endmatch);
		}

		continueB.pos.x = static_cast<float>((GetScreenWidth() / 2));
		continueB.pos.y = static_cast<float>(GetScreenHeight() / 2);
		DrawTexture(continueB.button, static_cast<int>(continueB.pos.x), static_cast<int>(continueB.pos.y), RAYWHITE);
		drawButton(mouse, continueB);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && continueB.isSelected == true)
		{
			PlaySound(optionS);
			resetMusic(gameplayMusic);
			bird2 = CreateBird(playerTexture);
			resetGame(bird, obstacles, pause, endmatch);
		}
	}

	void MenuWindow(Vector2 mouse)
	{
		UpdateMusicStream(menuMusic);
		BeginDrawing();
		DrawTexture(menuBack, 0, 0, RAYWHITE);

		DrawTexture(titleMenu, (GetScreenWidth() / 2) - (titleMenu.width / 2), 50, RAYWHITE);

		playSingleB.pos.x = static_cast<float>(GetScreenWidth() / 2) - (playSingleB.size.x / 2);
		playSingleB.pos.y = static_cast<float>(GetScreenHeight() / 2) - 100;
		drawButton(mouse, playSingleB);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && playSingleB.isSelected == true)
		{
			PlaySound(optionS);
			menu = MenuScenes::SinglePlay;
		}

		playMultiB.pos.x = static_cast<float>(GetScreenWidth() / 2) - (playSingleB.size.x / 2);
		playMultiB.pos.y = static_cast<float>(GetScreenHeight() / 2) - 50;
		drawButton(mouse, playMultiB);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && playMultiB.isSelected == true)
		{
			PlaySound(optionS);
			menu = MenuScenes::MultiPlay;
		}

		rulesB.pos.x = static_cast<float>(GetScreenWidth() / 2) - (rulesB.size.x / 2);
		rulesB.pos.y = static_cast<float>(GetScreenHeight() / 2);
		drawButton(mouse, rulesB);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && rulesB.isSelected == true)
		{
			PlaySound(optionS);
			menu = MenuScenes::Instructions;
		}

		creditsB.pos.x = static_cast<float>(GetScreenWidth() / 2) - (creditsB.size.x / 2);
		creditsB.pos.y = static_cast<float>(GetScreenHeight() / 2) + 50;
		drawButton(mouse, creditsB);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && creditsB.isSelected == true)
		{
			PlaySound(optionS);
			menu = MenuScenes::Credits;
		}

		exitB.pos.x = static_cast<float>(GetScreenWidth() / 2) - (exitB.size.x / 2);
		exitB.pos.y = static_cast<float>(GetScreenHeight() / 2) + 100;
		drawButton(mouse, exitB);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && exitB.isSelected == true)
		{
			PlaySound(optionS);
			menu = MenuScenes::Quit;
		}
		EndDrawing();
	}

	void CreditsWindow(Vector2 mouse)
	{

		backB.pos.x = 20.0f;
		backB.pos.y = static_cast<float>(GetScreenHeight() - 75);
		UpdateMusicStream(menuMusic);
		BeginDrawing();
		DrawTexture(menuBack, 0, 0, RAYWHITE);
		DrawTexture(credits, 5, 10, RAYWHITE);
		drawButton(mouse, backB);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && backB.isSelected == true)
		{
			PlaySound(optionS);
			menu = MenuScenes::MainMenu;
		}
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

	void DrawPause(Vector2 mouse)
	{
		
		DrawText("Paused", GetScreenWidth() / 2 - 170, GetScreenHeight() / 2 - 200, 100, BROWN);
		backB.pos.x = static_cast<float>(GetScreenWidth() / 2) - (backB.size.x);
		backB.pos.y = static_cast<float>(GetScreenHeight() / 2) - 50;
		drawButton(mouse, backB);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && backB.isSelected == true)
		{
			PlaySound(optionS);
			menu = MenuScenes::MainMenu;
			resetMusic(gameplayMusic);
			resetMusic(menuMusic);
			resetGame(bird, obstacles, pause, endmatch);
		}

		continueB.pos.x = static_cast<float>(GetScreenWidth() / 2);
		continueB.pos.y = static_cast<float>(GetScreenHeight() / 2) - 50;
		drawButton(mouse, continueB);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && continueB.isSelected == true)
		{
			PlaySound(optionS);
			pause = false;
		}
	}

	void resetMusic(Music& music) 
	{
		StopMusicStream(music);
		PlayMusicStream(music);
	}

	void drawButton(Vector2 mouse, Button& button) 
	{
		DrawTexture(button.button, static_cast<int>(button.pos.x), static_cast<int>(button.pos.y), RAYWHITE);
		if (optionsCollision(mouse, button))
		{
			button.isSelected = true;
			DrawTexture(button.buttonS, static_cast<int>(button.pos.x), static_cast<int>(button.pos.y), RAYWHITE);
		}
		else if (!optionsCollision(mouse, button))
		{
			button.isSelected = false;
		}

		
	}
}