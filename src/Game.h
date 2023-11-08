#pragma once
#include<iostream>
#include"raylib.h"

void Update();
void Draw();
void DrawCredit();
void GameLoop();
void WindowInstructions();
void UpdateMenu();
void CreditsWindow();
void backMenu();


namespace game
{
	void RunGame();
}