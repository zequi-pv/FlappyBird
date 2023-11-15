#pragma once
#include <string>
#include "raylib.h"

using namespace std;

enum class MenuScenes
{
	MainMenu,
	Play,
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
extern Buttons Texto[4];

void InitializeTexts();
void CheckSinglePlayer();
void CheckInstructions();
void CheckCredits();
void CheckQuit();
void ScenesSwitch();
void DrawButtons();
void DrawSinglePlayer();
void DrawInstruction();
void DrawCredits();
void CheckBack();
void DrawBack();

void DrawQuit();
