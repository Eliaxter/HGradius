#include "Player.h"

#include "raylib.h"

#include "Global.h"

namespace Game
{
	Player player1;
	float playerSpeed;

	int pointsPlayer = 5;
	int lifesPlayer = 3;

	static float playerPosX = screenWidth / 7;
	static float playerPosY = screenHeight / 7;

	static float playerWidth = 40.0f;
	static float playerHeight = 20.0f;

	void InitPlayer()
	{
		player1.rec.width = playerWidth;
		player1.rec.height = playerHeight;
		player1.rec.x = playerPosX;
		player1.rec.y = playerPosY;
		playerSpeed = 600.0f;
	}

	void DrawPlayer()
	{
		DrawRectangle(static_cast<int>(player1.rec.x), static_cast<int>(player1.rec.y), static_cast<int>(player1.rec.width), static_cast<int>(player1.rec.height), WHITE);
	}

	void MovePlayer()
	{
		if (IsKeyDown(KEY_W))
		{
			player1.rec.y -= playerSpeed * GetFrameTime();
		}
		if (IsKeyDown(KEY_S))
		{
			player1.rec.y += playerSpeed * GetFrameTime();
		}
	}
	
	void LimitMove()
	{
		if ((player1.rec.y) <= minScreenHeight)
		{
			player1.rec.y = minScreenHeight;
		}
		if ((player1.rec.y + player1.rec.height) >= screenHeight)
		{
			player1.rec.y = screenHeight - player1.rec.height;
		}
	}
}