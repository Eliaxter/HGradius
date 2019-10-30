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
	static float playerHeight = 80.0f;

	static Vector2 position;
	static Rectangle frameRec;
	static float currentFrame = 0;
	static float framesCounter = 0;

	static float maxCounter = 0.5f;

	void InitPlayer()
	{
		player1.rec.width = playerWidth;
		player1.rec.height = playerHeight;
		player1.rec.x = playerPosX;
		player1.rec.y = playerPosY;
		playerSpeed = 600.0f;
		player1.sprite = LoadTexture("assets/sprites/Sheep.png");
		frameRec = { 0.0f, 0.0f, static_cast<float>(player1.sprite.height), static_cast<float>(player1.sprite.width / 2) };
	}

	void DrawPlayer()
	{
		framesCounter += GetFrameTime();

		if (framesCounter >= (maxCounter))
		{
			framesCounter = 0;

			currentFrame++;
			if (currentFrame > 1)
				currentFrame = 0;

			frameRec.x = static_cast<float>(currentFrame*(player1.sprite.width / 2));
		}
		position = { player1.rec.x, player1.rec.y };

		DrawTextureRec(player1.sprite, frameRec, position, WHITE);
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