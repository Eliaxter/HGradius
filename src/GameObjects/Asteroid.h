#ifndef ASTEROID_H
#define ASTEROID_H

#include "raylib.h"

namespace Game
{
	struct Asteroids{
		Rectangle rec;
		bool isAlive;
		Texture2D sprite;
	};

	extern const int asteroidSize;

	extern Asteroids asteroid1[5];

	extern float speedAsteroid;

	void InitAsteroid();
	void DrawAsteroid();
}

#endif