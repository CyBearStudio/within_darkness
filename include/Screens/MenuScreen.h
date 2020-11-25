#ifndef MENUSCREEN_H_INCLUDED
#define MENUSCREEN_H_INCLUDED

#include "Screens/Screen.h"


class MenuScreen : public MenuScreen
{
public:
    MenuScreen(Game* game, bool blockE, bool blockU, bool blockR);
    void init(); // inherited
    void ProcessEvents(); // inherited
    void update(); // inherited
    void render(); // inherited
};

#endif // MENUSCREEN_H_INCLUDED
