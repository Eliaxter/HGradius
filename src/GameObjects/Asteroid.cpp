#include "Asteroid.h"

#include "raylib.h"

#include "Global.h"

namespace Game
{
	int const asteroidSize = 5;

	Asteroids asteroid1[asteroidSize] = { 0 };

	float speedAsteroid = 200.0f;

	static int oneAsteroid = 1;

	void InitAsteroid()
	{
		for (int i = 0; i < asteroidSize; i++)
		{
			asteroid1[i].rec.x = GetRandomValue(screenWidth / 2, screenWidth / 6);
			asteroid1[i].rec.y = GetRandomValue(screenHeight / 2, screenHeight / 6);
			asteroid1[i].rec.width = 30.0f;
			asteroid1[i].rec.height = 10.0f;
			asteroid1[i].isAlive = true;
			//asteroid1[i].sprite = LoadTexture();
		}
	}

	void DrawAsteroid()
	{
		for (int i = 0; i < oneAsteroid; i++)
		{
			DrawRectangle(static_cast<int>(asteroid1[i].rec.x), static_cast<int>(asteroid1[i].rec.y), static_cast<int>(asteroid1[i].rec.width), static_cast<int>(asteroid1[i].rec.height), WHITE);
		}
	}
}