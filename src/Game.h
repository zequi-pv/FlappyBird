#pragma once
#include<iostream>
#include"raylib.h"

namespace game
{
	

	void Update();
	void UpdateMultiPlayer();
	void Draw(Vector2 mouse);
	void DrawMultiPlayerGame(Vector2 mouse);
	void GameLoop(Vector2 mouse);
	void GameLoopMultiPlayer(Vector2 mouse);
	void WindowInstructions(Vector2 mouse);
	void MenuWindow(Vector2 mouse);
	void CreditsWindow(Vector2 mouse);
	void backMenu();
	void RunGame();
}