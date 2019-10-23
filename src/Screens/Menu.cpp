#include "Menu.h"

#include "raylib.h"

#include "Game.h"
#include "GamePlay.h"
#include "Global.h"

namespace Game
{
	static int fontSize1 = 20;
	static int fontSize2 = 30;

	static int coordTxt1Y = 420;
	static int coordTxt2Y = 480;
	static int coordTxt3Y = 500;

	void InitMenuScreen()
	{
		ClearBackground(BLACK);
	}

	void DrawTextMenu()
	{
		DrawText("HGradius", halfScreenWidth, halfScreenHeight, fontSize2, WHITE);
		DrawText("Menu", halfScreenWidth, coordTxt1Y, fontSize2, WHITE);
		DrawText("Press the key ENTER to play", halfScreenWidth, coordTxt2Y, fontSize1, WHITE);
		DrawText("Version: 0.2", halfScreenWidth, coordTxt3Y, fontSize1, WHITE);
	}

	void InputMenu()
	{
		if (IsKeyDown(KEY_ENTER))
		{
			state = GameState::Game;
			InitGame();
		}
		if (IsKeyDown(KEY_ESCAPE))
		{

		}
	}

	void Menu()
	{
		InitMenuScreen();
		DrawTextMenu();
		InputMenu();
	}
}