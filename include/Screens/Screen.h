#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include "Game.h"


class Screen
{
public:
	Screen(Game* game, bool blockE, bool blockU, bool blockR);
	virtual void init();
	virtual void processEvents();
	virtual void update();
	virtual void render();

private:
    Game* mGame;
	const bool blockEvents; // wether screen prevent next screens from processing events
	const bool blockUpdate; // wether screen prevent next screens from updating
	const bool blockRender; // wether screen prevent next screens from rendering
    
public:
    bool getBlockEvents(); // accessors
    bool getBlockUpdate();
    bool getBlockRender();
};

#endif // SCREEN_H_INCLUDED
