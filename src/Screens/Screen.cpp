#include "Screens/Screen.h"


Screen::Screen(Game* game, bool blockE, bool blockU, bool blockR) : mGame(game), blockEvents(blockE), blockUpdate(blockU), blockRender(blockR)
{
}

void Screen::init() 
{
    // virtual
}

void Screen::processEvents()
{
	// virtual
}

void Screen::update()
{
	// virtual
}

void Screen::render()
{
	// virtual
}

bool Screen::getBlockEvents()
{
    return blockEvents;
}

bool Screen::getBlockUpdate()
{
    return blockUpdate;
}

bool Screen::getBlockRender()
{
    return blockRender;
}
