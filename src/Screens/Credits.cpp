#include "Credits.h"

#include "raylib.h"

#include "Global.h"
#include "GamePlay.h"
#include "Game.h"

namespace Game
{
	void InitCreditsScreen()
	{
		ClearBackground(BLACK);
	}

	void DrawTextCredits()
	{
		DrawText("Credits", screenWidth / 2, screenHeight / 2, 30, WHITE);
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