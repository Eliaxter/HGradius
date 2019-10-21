#include "Player.h"

#include "raylib.h"

#include "Global.h"

namespace Game
{
	Rectangle player;
	float playerSpeed;

	int pointsPlayer = 5;
	int lifesPlayer = 3;

	static float playerPosX = screenWidth / 7;
	static float playerPosY = screenHeight / 7;

	static float playerWidth = 40.0f;
	static float playerHeight = 20.0f;

	void InitPlayer()
	{
		player.width = playerWidth;
		player.height = playerHeight;
		player.x = playerPosX;
		player.y = playerPosY;
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
		if ((player.y) <= minScreenHeight)
		{
			player.y = minScreenHeight;
		}
		if ((player.y + player.height) >= screenHeight)
		{
			player.y = screenHeight - player.height;
		}
	}
}