#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Logger.h"
#include "Options.h"


class Game
{
public:
	Game();
	void init();
	void run();

private:
	void processEvents();
	void update();
	void render();

private:
	sf::RenderWindow mWindow;
	Logger mLogger;
	Options mOptions;
	std::string version;
};


#endif // GAME_H_INCLUDED
