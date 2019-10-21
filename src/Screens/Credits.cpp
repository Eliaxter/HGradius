#include "Credits.h"

#include "raylib.h"

#include "Global.h"
#include "GamePlay.h"
#include "Game.h"

namespace Game
{
	static int fontSize1 = 30;
	static int fontSize2 = 20;

	static int textPosY = 400;

	void InitCreditsScreen()
	{
		ClearBackground(BLACK);
	}

	void DrawTextCredits()
	{
		DrawText("Credits", halfScreenWidth, halfScreenHeight, fontSize1, WHITE);
		DrawText("Version 0.1", halfScreenWidth, textPosY, fontSize2, WHITE);
	}

	void InputCredits()
	{
		if (IsKeyDown(KEY_B))
		{
			state = GameState::MenuFinal;
		}
	}

	void CreditsScreen() 
	{
		InitCreditsScreen();
		DrawTextCredits();
		InputCredits();
	}
}