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
		Credits,
		Close
	};

	extern GameState state;

	void Loop();
}

#endif