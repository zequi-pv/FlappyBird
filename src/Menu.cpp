#include <String>
#include"raylib.h"
#include"Menu.h"
#include"Game.h"
//#include"WindowSize.h"

using namespace std;

MenuScenes menu;
Buttons Texto[5];
Buttons back, pause, restart, resume;

extern bool isGameRunning;
static int fontSize = 40;
static int verticalSpacing = 120;


void InitializeTexts()
{
	for (int i = 0; i < 5; i++) {

		string buttonText;
		if (i == 0) buttonText = "SINGLEPLAYER";
		else if (i == 1) buttonText = "MULTIPLAYER";
		else if (i == 2) buttonText = "RULES";
		else if (i == 3) buttonText = "CREDITS";
		else if (i == 4) buttonText = "QUIT";

		float textWidth = static_cast<float>(MeasureText(buttonText.c_str(), fontSize));
		float textX = static_cast<float>(GetScreenWidth() / 2) - textWidth / 2;
		float textY = static_cast<float>(i * verticalSpacing + 50);


		Texto[i].text = buttonText;
		Texto[i].fontSize = fontSize;
		Texto[i].pos.x = textX;
		Texto[i].pos.y = textY;
		Texto[i].backgroundBttn.x = textX - 10;
		Texto[i].backgroundBttn.y = textY - 3;
		Texto[i].backgroundBttn.width = textWidth + 20;
		Texto[i].backgroundBttn.height = 50;
	}

	back.text = "BACK";

	float backTextWidth = static_cast<float>(MeasureText(back.text.c_str(), fontSize));
	float backTextX = static_cast<float>(GetScreenWidth() / 2) - backTextWidth / 2;
	float backTextY = static_cast<float>(4 * verticalSpacing + 50);

	back.fontSize = fontSize;
	back.pos.x = backTextX;
	back.pos.y = backTextY;
	back.backgroundBttn.x = backTextX - 10;
	back.backgroundBttn.y = backTextY - 3;
	back.backgroundBttn.width = backTextWidth + 20;
	back.backgroundBttn.height = 50;

	/*back.text = "PAUSE";

	float backTextWidth = static_cast<float>(MeasureText(back.text.c_str(), fontSize));
	float backTextX = static_cast<float>(SCREEN_WIDTH / 2) - backTextWidth / 2;
	float backTextY = static_cast<float>(4 * verticalSpacing + 50);

	back.fontSize = fontSize;
	back.pos.x = backTextX;
	back.pos.y = backTextY;
	back.backgroundBttn.x = backTextX - 10;
	back.backgroundBttn.y = backTextY - 3;
	back.backgroundBttn.width = backTextWidth + 20;
	back.backgroundBttn.height = 50;

	back.text = "RESTART";

	float backTextWidth = static_cast<float>(MeasureText(back.text.c_str(), fontSize));
	float backTextX = static_cast<float>(SCREEN_WIDTH / 2) - backTextWidth / 2;
	float backTextY = static_cast<float>(4 * verticalSpacing + 50);

	back.fontSize = fontSize;
	back.pos.x = backTextX;
	back.pos.y = backTextY;
	back.backgroundBttn.x = backTextX - 10;
	back.backgroundBttn.y = backTextY - 3;
	back.backgroundBttn.width = backTextWidth + 20;
	back.backgroundBttn.height = 50;

	back.text = "RESUME";

	float backTextWidth = static_cast<float>(MeasureText(back.text.c_str(), fontSize));
	float backTextX = static_cast<float>(SCREEN_WIDTH / 2) - backTextWidth / 2;
	float backTextY = static_cast<float>(4 * verticalSpacing + 50);

	back.fontSize = fontSize;
	back.pos.x = backTextX;
	back.pos.y = backTextY;
	back.backgroundBttn.x = backTextX - 10;
	back.backgroundBttn.y = backTextY - 3;
	back.backgroundBttn.width = backTextWidth + 20;
	back.backgroundBttn.height = 50;*/


}

void DrawSinglePlayer()
{
	DrawRectangleGradientV(static_cast<int>(Texto[0].backgroundBttn.x), static_cast<int>(Texto[0].backgroundBttn.y), static_cast<int>(Texto[0].backgroundBttn.width), static_cast<int>(Texto[0].backgroundBttn.height), BLACK, Fade(DARKPURPLE, 0.5f));
	DrawText(Texto[0].text.c_str(), static_cast<int> (Texto[0].pos.x), static_cast<int>(Texto[0].pos.y), static_cast<int> (Texto[0].fontSize), BLUE);

	if (CheckCollisionPointRec(GetMousePosition(), Texto[0].backgroundBttn))
	{
		DrawRectangle(static_cast<int>(Texto[0].backgroundBttn.x), static_cast<int>(Texto[0].backgroundBttn.y), static_cast<int>(Texto[0].backgroundBttn.width), static_cast<int>(Texto[0].backgroundBttn.height), Fade(BLACK, 0.50f));
		DrawText(Texto[0].text.c_str(), static_cast<int> (Texto[0].pos.x), static_cast<int>(Texto[0].pos.y), static_cast<int> (Texto[0].fontSize), RED);
	}
}

void CheckSinglePlayer()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), Texto[0].backgroundBttn))
	{
		menu = MenuScenes::SinglePlay;
	}
}

void DrawMultiPlayer()
{
	DrawRectangle(static_cast<int>(Texto[1].backgroundBttn.x), static_cast<int>(Texto[1].backgroundBttn.y), static_cast<int>(Texto[1].backgroundBttn.width), static_cast<int>(Texto[1].backgroundBttn.height), WHITE);
	DrawRectangleGradientV(static_cast<int>(Texto[1].backgroundBttn.x), static_cast<int>(Texto[1].backgroundBttn.y), static_cast<int>(Texto[1].backgroundBttn.width), static_cast<int>(Texto[1].backgroundBttn.height), BLACK, Fade(DARKPURPLE, 0.5f));
	DrawText(Texto[1].text.c_str(), static_cast<int> (Texto[1].pos.x), static_cast<int>(Texto[1].pos.y), static_cast<int> (Texto[1].fontSize), DARKBLUE);

	if (CheckCollisionPointRec(GetMousePosition(), Texto[1].backgroundBttn))
	{
		DrawRectangleLines(static_cast<int>(Texto[1].backgroundBttn.x), static_cast<int>(Texto[1].backgroundBttn.y), static_cast<int>(Texto[1].backgroundBttn.width), static_cast<int>(Texto[1].backgroundBttn.height + 2), RED);
		DrawRectangle(static_cast<int>(Texto[1].backgroundBttn.x), static_cast<int>(Texto[1].backgroundBttn.y), static_cast<int>(Texto[1].backgroundBttn.width), static_cast<int>(Texto[1].backgroundBttn.height), BLACK);
		DrawText(Texto[1].text.c_str(), static_cast<int> (Texto[1].pos.x), static_cast<int>(Texto[1].pos.y), static_cast<int> (Texto[1].fontSize), RED);
	}
}

void CheckMultiPlayer() 
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), Texto[1].backgroundBttn))
	{
		menu = MenuScenes::MultiPlay;
	}
}

void DrawInstruction()
{
	DrawRectangle(static_cast<int>(Texto[2].backgroundBttn.x), static_cast<int>(Texto[2].backgroundBttn.y), static_cast<int>(Texto[2].backgroundBttn.width), static_cast<int>(Texto[2].backgroundBttn.height), WHITE);
	DrawRectangleGradientV(static_cast<int>(Texto[2].backgroundBttn.x), static_cast<int>(Texto[2].backgroundBttn.y), static_cast<int>(Texto[2].backgroundBttn.width), static_cast<int>(Texto[2].backgroundBttn.height), BLACK, Fade(DARKPURPLE, 0.5f));
	DrawText(Texto[2].text.c_str(), static_cast<int> (Texto[2].pos.x), static_cast<int>(Texto[2].pos.y), static_cast<int> (Texto[2].fontSize), DARKBLUE);

	if (CheckCollisionPointRec(GetMousePosition(), Texto[2].backgroundBttn))
	{
		DrawRectangleLines(static_cast<int>(Texto[2].backgroundBttn.x - 1), static_cast<int>(Texto[2].backgroundBttn.y - 1), static_cast<int>(Texto[2].backgroundBttn.width + 2), static_cast<int>(Texto[2].backgroundBttn.height + 2), RED);
		DrawRectangle(static_cast<int>(Texto[2].backgroundBttn.x), static_cast<int>(Texto[2].backgroundBttn.y), static_cast<int>(Texto[2].backgroundBttn.width), static_cast<int>(Texto[2].backgroundBttn.height), BLACK);
		DrawText(Texto[2].text.c_str(), static_cast<int> (Texto[2].pos.x), static_cast<int>(Texto[2].pos.y), static_cast<int> (Texto[2].fontSize), RED);
	}
}

void CheckInstructions()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), Texto[2].backgroundBttn))
	{
		menu = MenuScenes::Instructions;
	}
}

void DrawCredits()
{
	DrawRectangleGradientV(static_cast<int>(Texto[3].backgroundBttn.x), static_cast<int>(Texto[3].backgroundBttn.y), static_cast<int>(Texto[3].backgroundBttn.width), static_cast<int>(Texto[3].backgroundBttn.height), BLACK, Fade(DARKPURPLE, 0.5f));
	DrawText(Texto[3].text.c_str(), static_cast<int>(Texto[3].pos.x), static_cast<int>(Texto[3].pos.y), static_cast<int>(Texto[3].fontSize), BLUE);

	if (CheckCollisionPointRec(GetMousePosition(), Texto[3].backgroundBttn))
	{
		DrawRectangle(static_cast<int>(Texto[3].backgroundBttn.x), static_cast<int>(Texto[3].backgroundBttn.y), static_cast<int>(Texto[3].backgroundBttn.width), static_cast<int>(Texto[3].backgroundBttn.height), BLACK);
		DrawText(Texto[3].text.c_str(), static_cast<int>(Texto[3].pos.x), static_cast<int>(Texto[3].pos.y), static_cast<int>(Texto[3].fontSize), RED);
	}
}

void CheckCredits()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), Texto[3].backgroundBttn))
	{
		menu = MenuScenes::Credits;
	}
}

void DrawQuit()
{
	DrawRectangleGradientV(static_cast<int>(Texto[4].backgroundBttn.x), static_cast<int>(Texto[4].backgroundBttn.y), static_cast<int>(Texto[4].backgroundBttn.width), static_cast<int>(Texto[4].backgroundBttn.height), BLACK, Fade(DARKPURPLE, 0.5f));
	DrawText(Texto[4].text.c_str(), static_cast<int>(Texto[4].pos.x), static_cast<int>(Texto[4].pos.y), static_cast<int>(Texto[4].fontSize), RED);

	if (CheckCollisionPointRec(GetMousePosition(), Texto[4].backgroundBttn))
	{
		DrawRectangle(static_cast<int>(Texto[4].backgroundBttn.x), static_cast<int>(Texto[4].backgroundBttn.y), static_cast<int>(Texto[4].backgroundBttn.width), static_cast<int>(Texto[4].backgroundBttn.height), BLACK);
		DrawText(Texto[4].text.c_str(), static_cast<int>(Texto[4].pos.x), static_cast<int>(Texto[4].pos.y), static_cast<int>(Texto[4].fontSize), RED);
	}
}

void CheckQuit()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), Texto[4].backgroundBttn))
	{
		menu = MenuScenes::Quit;
	}
}

void DrawBack()
{

	DrawRectangleGradientV(static_cast<int>(back.backgroundBttn.x), static_cast<int>(back.backgroundBttn.y), static_cast<int>(back.backgroundBttn.width), static_cast<int>(back.backgroundBttn.height), BLACK, Fade(DARKPURPLE, 0.5f));
	DrawText(back.text.c_str(), static_cast<int>(back.pos.x), static_cast<int>(back.pos.y), static_cast<int>(back.fontSize), RED);

	if (CheckCollisionPointRec(GetMousePosition(), back.backgroundBttn))
	{
		DrawRectangle(static_cast<int>(back.backgroundBttn.x), static_cast<int>(back.backgroundBttn.y), static_cast<int>(back.backgroundBttn.width), static_cast<int>(back.backgroundBttn.height), BLACK);
		DrawText(back.text.c_str(), static_cast<int>(back.pos.x), static_cast<int>(back.pos.y), static_cast<int>(back.fontSize), RED);
	}


}

void CheckBack()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), back.backgroundBttn))
	{
		menu = MenuScenes::MainMenu;
	}
}

void DrawButtons()
{
	BeginDrawing();
	DrawRectangleGradientV(GetScreenWidth() / 2 - 512, GetScreenHeight() / 2 - 384, static_cast <int>(GetScreenWidth()), static_cast <int>(GetScreenHeight()), BLACK, Fade(RED, 1.0f));

	if (menu == MenuScenes::Instructions || menu == MenuScenes::Credits)
	{
		DrawBack();
	}
	else if (menu == MenuScenes::MainMenu)
	{
		DrawSinglePlayer();
		DrawMultiPlayer();
		DrawInstruction();
		DrawCredits();
		DrawQuit();
	}

	EndDrawing();
}

void ScenesSwitch()
{
	switch (menu)
	{
	case MenuScenes::MainMenu:

		UpdateMenu();
		DrawButtons();

		break;

	case MenuScenes::SinglePlay:

		GameLoop();

		break;

	case MenuScenes::MultiPlay:

		GameLoopMultiPlayer();

		break;
	case MenuScenes::Instructions:

		WindowInstructions();

		break;

	case MenuScenes::Credits:

		CreditsWindow();

		break;

	case MenuScenes::Quit:

		isGameRunning = true;
		break;
	}
}