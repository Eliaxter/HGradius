#include "GamePlay.h"

#include "Global.h"
#include "Player.h"
#include "Enemy.h"
#include "Asteroid.h"
#include "Game.h"

namespace Game
{
	static bool pause = false;

	static int heightDivisor = 7;

	static int fontSizePause = 50;

	static float tenSeconds = 10.0f;

	void DrawGamePlay()
	{
		ClearBackground(BLACK);
	}

	void InitGame()
	{
		DrawGamePlay();
		InitPlayer();
		InitEnemy();
		DrawEnemy();
		InitAsteroid();
		DrawAsteroid();
		lifesPlayer = 3;
		limitEnemies = false;
		timer = 0.0f;
	}

	void DrawEnemys()
	{
		for (int i = 0; i < enemiesSize; i++)
		{
			if (limitEnemies == false)
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
				countEnemy++;
				if (countEnemy == enemiesSize)
				{
					limitEnemies = true;
				}
			}
		}
		countEnemy = 0;
		limitEnemies = false;
	}

	void MoveEnemys()
	{
		for (int i = 0; i < enemiesSize; i++)
		{
			if (enemies[i].isAlive == true)
			{
				enemies[i].rec.x -= speedEnemy * GetFrameTime();
			}
		}
	}

	void LimitScreenEnemy()
	{
		for (int i = 0; i < enemiesSize; i++)
		{
			if (enemies[i].rec.x <= minScreenWidth)
			{
				enemies[i].rec.x = screenWidth;
				enemies[i].rec.y = GetRandomValue(screenHeight, screenHeight / heightDivisor);
			}
		}

	}

	void DrawAsteroids()
	{
		if (timer / static_cast<float>(GetFPS()) > tenSeconds)
		{
			for (int i = 0; i < asteroidSize; i++)
			{
				//DrawRectangle(asteroid1[i].rec.x, asteroid1[i].rec.y, asteroid1[i].rec.width, asteroid1[i].rec.height, WHITE);
				DrawTexture(asteroid1[i].sprite, asteroid1[i].rec.x, asteroid1[i].rec.y, WHITE);
			}

		}
	}

	void MoveAsteroids()
	{
		for (int i = 0; i < asteroidSize; i++)
		{
			if (asteroid1[i].isAlive == true)
			{
				asteroid1[i].rec.x -= speedAsteroid * GetFrameTime();
			}
		}
	}

	void LimitScreenAsteroids()
	{
		for (int i = 0; i < asteroidSize; i++)
		{
			if (asteroid1[i].rec.x <= minScreenWidth)
			{
				asteroid1[i].rec.x = screenWidth;
				asteroid1[i].rec.y = GetRandomValue(screenHeight, screenHeight / heightDivisor);
			}
		}
	}

	void CheckCollisionEnemyPlayer()
	{
		for (int i = 0; i < enemiesSize; i++)
		{
			if (CheckCollisionRecs(player1.rec, enemies[i].rec))
			{
				enemies[i].isAlive = false;
				lifesPlayer--;
			}
		}
		
	}

	void CheckLifesPlayer() 
	{
		if (lifesPlayer <= 0)
		{
			state = GameState::MenuFinal;
		}
	}

	void ShootInput()
	{
		if (IsKeyDown(KEY_P))
		{
			DrawRectangle(player1.rec.x, player1.rec.y / 2, 30, 20, WHITE);
		}
	}

	void PauseInput()
	{
		if (IsKeyPressed(KEY_SPACE))
		{
			pause = true;
		}
	}

	void BackMenuInput()
	{
		if (IsKeyDown(KEY_M))
		{
			state = GameState::GameMenu;
		}
	}

	void Update()
	{
		if (pause == false)
		{
			MovePlayer();
			LimitMove();
			MoveEnemys();
			LimitScreenEnemy();
			MoveAsteroids();
			LimitScreenAsteroids();
			CheckCollisionEnemyPlayer();
			CheckLifesPlayer();
			ShootInput();
			PauseInput();
			BackMenuInput();
		}
		else
		{
			DrawText("PAUSA", halfScreenWidth, halfScreenHeight, fontSizePause, WHITE);
			if (IsKeyPressed(KEY_SPACE))
			{
				pause = false;
			}
		}
		
	}

	void Draw()
	{
		DrawPlayer();
		DrawAsteroids();
		DrawEnemys();
	}
}