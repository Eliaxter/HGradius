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
	extern Bullet bullets;

	void InitBullet();
	void DrawBullet();
}

#endif

