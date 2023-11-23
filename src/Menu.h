#pragma once
#include <string>
#include "raylib.h"

using namespace std;

enum class MenuScenes
{
	MainMenu,
	SinglePlay,
	MultiPlay,
	Instructions,
	Credits,
	Quit
};
extern MenuScenes menu;

struct Buttons
{
	string text{};
	Vector2 pos{};
	int fontSize{};

	Rectangle backgroundBttn{};
};
extern Buttons Texto[5];

void InitializeTexts();
void CheckSinglePlayer();
void CheckMultiPlayer();
void CheckInstructions();
void CheckCredits();
void CheckQuit();
void ScenesSwitch();
void DrawButtons();
void DrawSinglePlayer();
void DrawMultiPlayer();
void DrawInstruction();
void DrawCredits();
void CheckBack();
void DrawBack();

void DrawQuit();
