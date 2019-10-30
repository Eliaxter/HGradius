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
	void MoveBullets();
	void LimitScreenAsteroids();
	void LimitScreenBullet();
	void CheckCollisionEnemyPlayer();
	void CheckCollisionBulletEnemy();
	void CheckLifesPlayer();
	void ShootInput();
	void PauseInput();
	void BackMenuInput();
	void Update();
	void Draw();
}

#endif