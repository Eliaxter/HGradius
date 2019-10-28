#include "Credits.h"

#include "raylib.h"

#include "Global.h"
#include "GamePlay.h"
#include "Game.h"

namespace Game
{
	static int fontSize1 = 30;
	static int fontSize2 = 20;

	static int textPosY1 = 400;
	static int textPosY2 = 440;

	void InitCreditsScreen()
	{
		ClearBackground(BLACK);
	}

	void DrawTextCredits()
	{
		DrawText("Credits", halfScreenWidth, halfScreenHeight, fontSize1, WHITE);
		DrawText("Version 0.2", halfScreenWidth, textPosY1, fontSize2, WHITE);
		DrawText("Back to Final: B", halfScreenWidth, textPosY2, fontSize2, WHITE);
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