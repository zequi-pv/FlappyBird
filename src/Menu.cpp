#include <String>
#include "raylib.h"
#include "Menu.h"
#include "Game.h"
//#include"WindowSize.h"

using namespace std;

namespace game
{
	MenuScenes menu;
	
	extern bool isGameRunning;

	void ScenesSwitch()
	{
		Vector2 mouse = { static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) };

		switch (menu)
		{
		case MenuScenes::MainMenu:

			MenuWindow(mouse);

			break;

		case MenuScenes::SinglePlay:

			GameLoop(mouse);

			break;

		case MenuScenes::MultiPlay:

			GameLoopMultiPlayer(mouse);

			break;
		case MenuScenes::Instructions:

			WindowInstructions(mouse);

			break;

		case MenuScenes::Credits:

			CreditsWindow(mouse);

			break;

		case MenuScenes::Quit:

			isGameRunning = true;
			break;
		}
	}
}