#include "Screens/Screen.h"


Screen::Screen(Game* game, bool blockE, bool blockU, bool blockR) : mGame(game), blockEvents(blockE), blockUpdate(blockU), blockRender(blockR)
{
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
