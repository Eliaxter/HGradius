#include "Global.h"

#include "raylib.h"

namespace Game
{
	const int screenWidth = 1280;
	const int screenHeight = 720;

	void InitWindowGame()
	{
		InitWindow(screenWidth, screenHeight, "HGradius");
	}
}

