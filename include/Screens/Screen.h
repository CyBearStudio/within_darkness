#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include "Game.h"


class Screen
{
public:
	Screen(Game* game, bool blockE, bool blockU, bool blockR);
	virtual void processEvents();
	virtual void update();
	virtual void render();

private:
    Game* mGame;
	const bool blockEvents;
	const bool blockUpdate;
	const bool blockRender;
    
public:
    bool getBlockEvents();
    bool getBlockUpdate();
    bool getBlockRender();
};

#endif // SCREEN_H_INCLUDED
