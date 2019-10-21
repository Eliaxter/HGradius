#include "Global.h"

#include "raylib.h"

namespace Game
{
	int screenWidth = 1280;
	int screenHeight = 720;

	void InitWindowGame()
	{
		InitWindow(screenWidth, screenHeight, "HGradius");
	}
}

