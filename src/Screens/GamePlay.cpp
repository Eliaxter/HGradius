#include "GamePlay.h"

#include "Global.h"
#include "Player.h"
#include "Enemy.h"
#include "Game.h"

namespace Game
{
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
	}

	void DrawEnemys()
	{
		for (int i = 0; i < 50; i++)
		{
			if (enemies[i].isAlive == true)
			{
				DrawRectangle(static_cast<int>(enemies[i].pos.x), static_cast<int>(enemies[i].pos.y), static_cast<int>(enemies[i].pos.width), static_cast<int>(enemies[i].pos.height), GREEN);
			}
		}
	}

	void MoveEnemys()
	{
		for (int i = 0; i < 50; i++)
		{
			if (enemies[i].isAlive == true)
			{
				enemies[i].pos.x -= 500.0f * GetFrameTime();
			}
		}
	}

	void LimitScreenEnemy()
	{
		for (int i = 0; i < 50; i++)
		{
			if (enemies[i].pos.x <= 0)
			{
				enemies[i].pos.x = screenWidth;
				enemies[i].pos.y = GetRandomValue(screenHeight, screenHeight / 7);
			}
		}

	}

	void CheckCollisionEnemyPlayer()
	{
		for (int i = 0; i < 50; i++)
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

	void Update()
	{
		MovePlayer();
		LimitMove();
		MoveEnemys();
		LimitScreenEnemy();
		CheckCollisionEnemyPlayer();
		CheckLifesPlayer();
	}

	void Draw()
	{
		DrawPlayer();
		DrawEnemys();
	}
}