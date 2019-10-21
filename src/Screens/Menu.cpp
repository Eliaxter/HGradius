#include "Menu.h"

#include "raylib.h"

#include "Game.h"
#include "GamePlay.h"
#include "Global.h"

namespace Game
{
	void InitMenuScreen()
	{
		ClearBackground(BLACK);
	}

	void DrawTextMenu()
	{
		DrawText("HGradius", screenWidth / 2, screenHeight / 2, 30, WHITE);
		DrawText("Menu", screenWidth / 2, 420, 30, WHITE);
		DrawText("Press the key ENTER to play", screenWidth / 2, 480, 20, WHITE);
		DrawText("Version: 0.1", screenWidth / 2, 500, 20, WHITE);
	}

	void InputMenu()
	{
		if (IsKeyDown(KEY_ENTER))
		{
			state = GameState::Game;
			InitGame();
		}
	}

	void Menu()
	{
		InitMenuScreen();
		DrawTextMenu();
		InputMenu();
	}
}