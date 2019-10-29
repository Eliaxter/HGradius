#include "GamePlay.h"

#include "Global.h"
#include "Player.h"
#include "Enemy.h"
#include "Asteroid.h"
#include "Bullet.h"
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
		InitBullet();
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
				enemyPosition = { enemies[i].rec.x -30.0f, enemies[i].rec.y - enemies[i].rec.y / 3};

				DrawTextureRec(enemies[i].sprite, frameRec, enemyPosition, WHITE);
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

	void MoveBullets()
	{
		bullets.rec.x += 600.0f * GetFrameTime();
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
		if (IsKeyDown(KEY_SPACE))
		{
			DrawBullet();
		}
	}

	void PauseInput()
	{
		if (IsKeyPressed(KEY_P))
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
			MoveBullets();
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
			if (IsKeyPressed(KEY_P))
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