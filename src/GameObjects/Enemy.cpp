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
	static float enemyHeight = 250.0f;

	static int oneEnemy = 1;

	Vector2 enemyPosition;
	Rectangle frameRec;
	float currentFrame = 0;
	float framesCounter = 0;

	float maxCounter = 0.5f;

	void InitEnemy()
	{
		for (int i = 0; i < enemiesSize; i++)
		{
			enemies[i].rec.x = GetRandomValue(screenWidth, screenWidth / 2);
			enemies[i].rec.y = GetRandomValue(screenHeight, screenHeight / 7);
			enemies[i].rec.width = enemyWidth;
			enemies[i].rec.height = enemyHeight;
			enemies[i].isAlive = true;
			enemies[i].sprite = LoadTexture("assets/sprites/Sheep-2.png");
			frameRec = { 0.0f, 0.0f, static_cast<float>(enemies[i].sprite.height / 2), static_cast<float>(enemies[i].sprite.width / 2) };

		}
	}

	void DrawEnemy()
	{
		for (int i = 0; i < oneEnemy; i++)
		{
			framesCounter += GetFrameTime();

			if (framesCounter >= (maxCounter))
			{
				framesCounter = 0;

				currentFrame++;
				if (currentFrame > 1)
					currentFrame = 0;

				frameRec.x = static_cast<float>(currentFrame*(enemies[i].sprite.width / 2));
			}
			enemyPosition = { enemies[i].rec.x, enemies[i].rec.y };

			DrawTextureRec(enemies[i].sprite, frameRec, enemyPosition, WHITE);
			//DrawRectangle(static_cast<int>(enemies[i].rec.x), static_cast<int>(enemies[i].rec.y), static_cast<int>(enemies[i].rec.width), static_cast<int>(enemies[i].rec.height), GREEN);
		}
	}

}