#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

namespace Game
{
	extern Rectangle player;
	extern float playerSpeed;

	extern int pointsPlayer;
	extern int lifesPlayer;

	void InitPlayer();
	void DrawPlayer();
	void MovePlayer();
	void LimitMove();
}

#endif