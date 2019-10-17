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
		DrawText("Menu", screenWidth / 2, screenHeight / 2, 30, WHITE);
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