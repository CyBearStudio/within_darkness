#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include "Game.h"


class Screen
{
public:
	Screen(Game* game, bool blockE, bool blockU, bool blockR);
	virtual void init() = 0;
	virtual void processEvents() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

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
