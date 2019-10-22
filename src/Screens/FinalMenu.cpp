#include "FinalMenu.h"

#include "raylib.h"

#include "Game.h"
#include "Global.h"

namespace Game
{

	static int fontSize = 30;
	static int fontSize2 = 20;

	static int coordTxT1Y = 400;
	static int coordTxT2Y = 440;

	void InitScreenFinalMenu() 
	{
		ClearBackground(BLACK);
	}

	void DrawTextFinalMenu()
	{
		DrawText("End of Game", halfScreenWidth, halfScreenHeight, fontSize, WHITE);
		DrawText("Press M to return to menu", halfScreenWidth, coordTxT1Y, fontSize2, WHITE);
		DrawText("Press C to view the credits", halfScreenWidth, coordTxT2Y, fontSize2, WHITE);
	}

	void InputFinalMenu()
	{
		if (IsKeyDown(KEY_C))
		{
			state = GameState::Credits;
		}
		if (IsKeyDown(KEY_M))
		{
			state = GameState::GameMenu;
		}
	}

	void FinalMenu()
	{
		InitScreenFinalMenu();
		DrawTextFinalMenu();
		InputFinalMenu();
	}
}