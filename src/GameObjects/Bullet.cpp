#include "Bullet.h"

#include "raylib.h"

#include "Player.h"

namespace Game
{
	Bullet bullets;

	void InitBullet()
	{
		bullets.rec.x = player1.rec.x;
		bullets.rec.y = player1.rec.y / 2;
		bullets.rec.width = 30.0f;
		bullets.rec.height = 20.0f;
		bullets.isAlive = true;
	}

	void DrawBullet()
	{
		DrawRectangle(bullets.rec.x, bullets.rec.y, bullets.rec.width, bullets.rec.height, WHITE);
	}
}