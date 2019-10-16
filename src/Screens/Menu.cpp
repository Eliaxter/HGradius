#include "Menu.h"

#include "raylib.h"

#include "Game.h"

namespace Game
{
	void InitMenuScreen()
	{
		ClearBackground(BLACK);
	}

	void DrawTextMenu()
	{
		DrawText("Menu", 1280 / 2, 720 / 2, 30, WHITE);
	}

	void InputMenu()
	{
		if (IsKeyDown(KEY_ENTER))
		{
			state = GameState::Game;
		}
	}

	void Menu()
	{
		InitMenuScreen();
		DrawTextMenu();
		InputMenu();
	}
}