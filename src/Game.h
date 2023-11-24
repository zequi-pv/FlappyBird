#pragma once
#include<iostream>
#include"raylib.h"

namespace game
{
	void Update();
	void UpdateMultiPlayer();
	void Draw();
	void DrawMultiPlayerGame();
	void GameLoop();
	void GameLoopMultiPlayer();
	void WindowInstructions();
	void UpdateMenu();
	void CreditsWindow();
	void backMenu();
	void RunGame();
}