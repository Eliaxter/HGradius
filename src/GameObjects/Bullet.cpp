#include "Bullet.h"

#include "raylib.h"

#include "Player.h"

namespace Game
{
	const int bulletSize = 5;
	Bullet bullets[bulletSize] = { 0 };

	void InitBullet()
	{
		for (int i = 0; i < bulletSize; i++)
		{
			bullets[i].rec.x = player1.rec.x + 75;
			bullets[i].rec.y = player1.rec.y - 75;
			bullets[i].rec.width = 30.0f;
			bullets[i].rec.height = 20.0f;
			bullets[i].isAlive = false;
		}
	}

	void DrawBullet()
	{
		for (int i = 0; i < bulletSize; i++)
		{
			DrawRectangle(bullets[i].rec.x, bullets[i].rec.y, bullets[i].rec.width, bullets[i].rec.height, WHITE);
		}
	}
}