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
			DrawRectangle(enemys[i].x, enemys[i].y, enemys[i].width, enemys[i].height, GREEN);
		}
	}

	void MoveEnemys()
	{
		for (int i = 0; i < 50; i++)
		{
			enemys[i].x -= 500.0f * GetFrameTime();
		}
	}

	void LimitScreenEnemy()
	{
		for (int i = 0; i < 50; i++)
		{
			if (enemys[i].x <= 0)
			{
				enemys[i].x = screenWidth;
				enemys[i].y = GetRandomValue(screenHeight, screenHeight / 7);
			}
		}

	}

	void CheckCollisionEnemyPlayer()
	{
		for (int i = 0; i < 1; i++)
		{
			if (CheckCollisionRecs(player, enemys[i]))
			{
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