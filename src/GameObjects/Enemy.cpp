#include "Enemy.h"

#include "raylib.h"

#include "Global.h"

namespace Game 
{
	const int enemysSize = 50;
	Rectangle enemys[enemysSize] = { 0 };

	void InitEnemy()
	{
		for (int i = 0; i < 1; i++)
		{
			enemys[i].x = GetRandomValue(screenWidth, screenWidth / 2);
			enemys[i].y = GetRandomValue(screenHeight, screenHeight / 7);
			enemys[i].width = 50.0f;
			enemys[i].height = 15.0f;
		}
	}

	void DrawEnemy()
	{
		for (int i = 0; i < 1; i++)
		{
			DrawRectangle(enemys[i].x, enemys[i].y, enemys[i].width, enemys[i].height, GREEN);
		}
	}

}