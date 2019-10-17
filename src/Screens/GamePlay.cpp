#include "GamePlay.h"

#include "Global.h"
#include "Player.h"
#include "Enemy.h"

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
			}
		}

	}

	void Update()
	{
		DrawEnemys();
		MovePlayer();
		LimitMove();
		MoveEnemys();
		LimitScreenEnemy();
	}
	void Draw()
	{
		DrawPlayer();
		DrawEnemys();
	}
}