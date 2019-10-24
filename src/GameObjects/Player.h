#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

namespace Game
{
	struct Player {
		Rectangle rec;
		bool isAlive;
		Texture2D sprite;
	};
	extern Player player1;
	extern float playerSpeed;

	extern int pointsPlayer;
	extern int lifesPlayer;

	void InitPlayer();
	void DrawPlayer();
	void MovePlayer();
	void LimitMove();
}

#endif