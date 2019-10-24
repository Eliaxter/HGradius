#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"

namespace Game
{
	struct Enemy {
		Rectangle rec;
		bool isAlive;
		Texture2D sprite;
	};

	extern Enemy enemies[5];

	extern const int enemiesSize;

	extern float speedEnemy;

	extern int countEnemy;

	extern bool limitEnemies;

	void InitEnemy();
	void DrawEnemy();
}

#endif