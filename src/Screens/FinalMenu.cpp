#include "FinalMenu.h"

#include "raylib.h"

#include "Game.h"
#include "Global.h"

namespace Game
{

	static int fontSize = 30;

	void InitScreenFinalMenu() 
	{
		ClearBackground(BLACK);
	}

	void DrawTextFinalMenu()
	{
		DrawText("End of Game", halfScreenWidth, halfScreenHeight, fontSize, WHITE);
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