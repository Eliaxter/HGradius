#include "GamePlay.h"

#include "Global.h"
#include "Player.h"
#include "Enemy.h"
#include "Game.h"

namespace Game
{
	static bool pause = false;

	static int heightDivisor = 7;

	static int fontSizePause = 50;

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
		lifesPlayer = 3;
		limitEnemies = false;
	}

	void DrawEnemys()
	{
		for (int i = 0; i < enemiesSize; i++)
		{
			if (limitEnemies == false)
			{
				DrawRectangle(static_cast<int>(enemies[i].pos.x), static_cast<int>(enemies[i].pos.y), static_cast<int>(enemies[i].pos.width), static_cast<int>(enemies[i].pos.height), GREEN);
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
				enemies[i].pos.x -= speedEnemy * GetFrameTime();
			}
		}
	}

	void LimitScreenEnemy()
	{
		for (int i = 0; i < enemiesSize; i++)
		{
			if (enemies[i].pos.x <= minScreenWidth)
			{
				enemies[i].pos.x = screenWidth;
				enemies[i].pos.y = GetRandomValue(screenHeight, screenHeight / heightDivisor);
			}
		}

	}

	void CheckCollisionEnemyPlayer()
	{
		for (int i = 0; i < enemiesSize; i++)
		{
			if (CheckCollisionRecs(player, enemies[i].pos))
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

	void PauseInput()
	{
		if (IsKeyDown(KEY_SPACE))
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
			CheckCollisionEnemyPlayer();
			CheckLifesPlayer();
			PauseInput();
			BackMenuInput();
		}
		else
		{
			DrawText("PAUSA", halfScreenWidth, halfScreenHeight, fontSizePause, WHITE);
			if (IsKeyDown(KEY_SPACE))
			{
				pause = false;
			}
			if (IsKeyUp(KEY_SPACE))
			{
				pause = true;
			}
		}
		
	}

	void Draw()
	{
		DrawPlayer();
		DrawEnemys();
	}
}