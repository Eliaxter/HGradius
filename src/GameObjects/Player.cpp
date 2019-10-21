#include "Player.h"

#include "raylib.h"

#include "Global.h"

namespace Game
{
	Rectangle player;
	float playerSpeed;

	int pointsPlayer = 5;
	int lifesPlayer = 3;

	void InitPlayer()
	{
		player.width = 40.0f;
		player.height = 20.0f;
		player.x = screenWidth / 7;
		player.y = screenHeight / 7;
		playerSpeed = 600.0f;
	}

	void DrawPlayer()
	{
		DrawRectangle(static_cast<int>(player.x), static_cast<int>(player.y), static_cast<int>(player.width), static_cast<int>(player.height), WHITE);
	}

	void MovePlayer()
	{
		if (IsKeyDown(KEY_W))
		{
			player.y -= playerSpeed * GetFrameTime();
		}
		if (IsKeyDown(KEY_S))
		{
			player.y += playerSpeed * GetFrameTime();
		}
	}
	
	void LimitMove()
	{
		if ((player.y) <= 0)
		{
			player.y = 0;
		}
		if ((player.y + player.height) >= screenHeight)
		{
			player.y = screenHeight - player.height;
		}
	}
}