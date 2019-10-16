#ifndef GAME_H
#define GAME_H

namespace Game
{
	enum GameState 
	{
		Menu,
		FeedBack,
		Game,
		MenuFinal,
		Credits
	};

	extern GameState state;

	void GameLoop();
}

#endif