#ifndef GAME_H
#define GAME_H

namespace Game
{
	enum GameState 
	{
		GameMenu,
		FeedBack,
		Game,
		MenuFinal,
		Credits
	};

	extern GameState state;

	void GameLoop();
}

#endif