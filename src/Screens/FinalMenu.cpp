#include "FinalMenu.h"

#include "raylib.h"

#include "Game.h"

namespace Game
{
	void InitScreenFinalMenu() 
	{
		ClearBackground(BLACK);
	}

	void DrawTextFinalMenu()
	{
		DrawText("End of Game", 1280 / 2, 720 / 2, 30, WHITE);
	}

	void InputFinalMenu()
	{
		if (IsKeyDown(KEY_C))
		{
			state = GameState::Credits;
		}
	}

	void FinalMenu()
	{
		InitScreenFinalMenu();
		DrawTextFinalMenu();
		InputFinalMenu();
	}
}