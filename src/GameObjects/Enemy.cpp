#include "Enemy.h"

#include "raylib.h"

#include "Global.h"

namespace Game 
{
	const int enemiesSize = 5;
	Enemy enemies[enemiesSize] = { 0 };

	float speedEnemy = 500.0f;

	int countEnemy = 0;

	bool limitEnemies;

	static float enemyWidth = 50.0f;
	static float enemyHeight = 15.0f;

	static int oneEnemy = 1;

	void InitEnemy()
	{
		for (int i = 0; i < enemiesSize; i++)
		{
			enemies[i].rec.x = GetRandomValue(screenWidth, screenWidth / 2);
			enemies[i].rec.y = GetRandomValue(screenHeight, screenHeight / 7);
			enemies[i].rec.width = enemyWidth;
			enemies[i].rec.height = enemyHeight;
			enemies[i].isAlive = true;
			//enemies[i].sprite = LoadTexture();
		}
	}

	void DrawEnemy()
	{
		for (int i = 0; i < oneEnemy; i++)
		{
			DrawRectangle(static_cast<int>(enemies[i].rec.x), static_cast<int>(enemies[i].rec.y), static_cast<int>(enemies[i].rec.width), static_cast<int>(enemies[i].rec.height), GREEN);
		}
	}

}