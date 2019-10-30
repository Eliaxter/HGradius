#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"

namespace Game
{
	struct Bullet{
		Rectangle rec;
		bool isAlive;
		Texture2D sprite;
	};
	extern const int bulletSize;
	extern Bullet bullets[5];

	void InitBullet();
	void DrawBullet();
}

#endif

