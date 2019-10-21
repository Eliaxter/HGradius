#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"

namespace Game
{
	struct Enemy {
		Rectangle pos;
		bool isAlive;
	};
	extern Enemy enemies[50];

	void InitEnemy();
	void DrawEnemy();
}

#endif