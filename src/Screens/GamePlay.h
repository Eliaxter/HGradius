#ifndef GAMEPLAY_H
#define GAMEPLAY_H

namespace Game
{
	void DrawGamePlay();
	void InitGame();
	void DrawEnemys();
	void MoveEnemys();
	void LimitScreenEnemy();
	void DrawAsteroids();
	void MoveAsteroids();
	void LimitScreenAsteroids();
	void CheckCollisionEnemyPlayer();
	void CheckLifesPlayer();
	void PauseInput();
	void BackMenuInput();
	void BackGround();
	void Update();
	void Draw();
}

#endif