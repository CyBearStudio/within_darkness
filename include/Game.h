#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Logger.h"
#include "Options.h"
#include "ResourceManager.h"


class Game
{
public:
	Game();
	void init(); // initializing
	void run(); // main game loop
	void quit(); // closes the game

private:
	void processEvents(); // passing events to the right screen
	void update(); // updating the screens
	void render(); // rendering the screens

private:
	bool mIsRunning; // set to false to quit the game
	sf::RenderWindow mWindow; // the main window
	Logger mLogger; // logger object to write in log file and console
	Options mOptions; // options object to handle game settings
	std::string mVersion; // version number stored in string for rendering conveniency
    sf::Font mFont; // the game font, currently Roboto Regular
	sf::Clock mUpdateClock; // clock to measure time between updates
    sf::Clock mFPSClock; // clock to measure frame rate
	sf::Time mTimePerFrame; // time between each frame (0 for no limit)
	sf::Clock mAlphaClock; // clock to drive alpha value of info text in title screen
    
public:
    Logger& getLogger(); // returns the reference to the Logger object
};


#endif // GAME_H_INCLUDED
