#ifndef GAMEPLAY_H
#define GAMEPLAY_H

namespace Game
{
	void DrawGamePlay();
	void InitGame();
	void DrawEnemys();
	void MoveEnemys();
	void LimitScreenEnemy();
	void CheckCollisionEnemyPlayer();
	void CheckLifesPlayer();
	void PauseInput();
	void Update();
	void Draw();
}

#endif