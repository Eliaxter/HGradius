#include "Global.h"

#include "raylib.h"

namespace Game
{
	int screenWidth = 1280;
	int screenHeight = 720;

	int minScreenWidth = 0;
	int minScreenHeight = 0;

	int halfScreenWidth = screenWidth / 2;
	int halfScreenHeight = screenHeight / 2;

	void InitWindowGame()
	{
		InitWindow(screenWidth, screenHeight, "HGradius");
	}
}

