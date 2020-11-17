#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Logger.h"
#include "Options.h"


class Game
{
public:
	Game();
	void init(); // initializing
	void run(); // main game loop

private:
	void processEvents(); // passing events to the right screen
	void update(); // updating the screens
	void render(); // rendering the screens

private:
	sf::RenderWindow mWindow; // the main window
	Logger mLogger; // logger object to write in log file and console
	Options mOptions; // options object to handle game settings
	std::string version; // version number stored in string for rendering conveniency
    sf::Font mFont; // the game font, currently Roboto Regular
    sf::Clock mClock; // the main clock to handle frame rate
    
public:
    Logger& getLogger(); // returns the reference to the Logger object
};


#endif // GAME_H_INCLUDED
