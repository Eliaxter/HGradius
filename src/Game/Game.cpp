#include "Game.h"

#include "raylib.h"

#include "Global.h"

namespace Game
{
	void GameLoop()
	{
		InitWindowGame();
		while (!WindowShouldClose())
		{
			BeginDrawing();
			ClearBackground(BLACK);
			DrawText("Hola", 500, 500, 20, WHITE);
			EndDrawing();
		}

	}
}

