#pragma once
#pragma once
#include"Game.h"
#include"raylib.h"
#include<iostream>
/*static*/ void Update();
/*static*/ void Draw();
/*static*/ void DrawCredit();
void GameLoop();
void WindowInstructions();
void UpdateMenu();
void CreditsWindow();
void backMenu();

namespace game
{
	void RunGame();
}