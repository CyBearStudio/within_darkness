#ifndef MENUSCREEN_H_INCLUDED
#define MENUSCREEN_H_INCLUDED

#include "Screens/Screen.h"


class MenuScreen : public Screen
{
public:
    MenuScreen(Game* game, bool blockE, bool blockU, bool blockR);
    void init() override;
    void processEvents() override;
    void update() override;
    void render() override;
};

#endif // MENUSCREEN_H_INCLUDED
