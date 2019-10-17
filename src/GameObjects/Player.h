#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

namespace Game
{
	extern Rectangle player;
	extern float playerSpeed;

	void InitPlayer();
	void DrawPlayer();
	void MovePlayer();
	void LimitMove();
}

#endif