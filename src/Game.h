#pragma once
#include<iostream>
#include"raylib.h"

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

namespace game
{
	void RunGame();
}