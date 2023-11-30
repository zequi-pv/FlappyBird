#pragma once
#include <string>
#include "raylib.h"

using namespace std;

namespace game
{
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

	void ScenesSwitch();
	
}