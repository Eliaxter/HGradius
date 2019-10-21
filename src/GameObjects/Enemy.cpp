#include "Enemy.h"

#include "raylib.h"

#include "Global.h"

namespace Game 
{
	const int enemiesSize = 50;
	Enemy enemies[enemiesSize] = { 0 };

	void InitEnemy()
	{
		for (int i = 0; i < 50; i++)
		{
			enemies[i].pos.x = GetRandomValue(screenWidth, screenWidth / 2);
			enemies[i].pos.y = GetRandomValue(screenHeight, screenHeight / 7);
			enemies[i].pos.width = 50.0f;
			enemies[i].pos.height = 15.0f;
			enemies[i].isAlive = true;
		}
	}

	void DrawEnemy()
	{
		for (int i = 0; i < 1; i++)
		{
			DrawRectangle(static_cast<int>(enemies[i].pos.x), static_cast<int>(enemies[i].pos.y), static_cast<int>(enemies[i].pos.width), static_cast<int>(enemies[i].pos.height), GREEN);
		}
	}

}