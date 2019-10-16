#include "Game.h"

#include "raylib.h"

#include "Global.h"
#include "Menu.h"
#include "GamePlay.h"
#include "FinalMenu.h"
#include "Credits.h"

namespace Game
{
	GameState state = GameState::Menu;

	void GameLoop()
	{
		InitWindowGame();
		while (!WindowShouldClose())
		{
			BeginDrawing();
			if (state == GameState::Menu)
			{
				Menu();
			}
			if (state == GameState::Game)
			{
				Update();
				Draw();
			}
			if (state == GameState::MenuFinal)
			{
				FinalMenu();
			}
			EndDrawing();
		}

	}
}

