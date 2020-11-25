#ifndef LEVELSCREEN_H_INCLUDED
#define LEVELSCREEN_H_INCLUDED

#include "Screens/Screen.h"


class LevelScreen : public Screen
{
public:
    LevelScreen(Game* game, bool blockE, bool blockU, bool blockR);
    void init(); // inherited
    void ProcessEvents(); // inherited
    void update(); // inherited
    void render(); // inherited
};

#endif // LEVELSCREEN_H_INCLUDED
