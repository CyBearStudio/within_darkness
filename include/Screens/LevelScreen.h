#ifndef LEVELSCREEN_H_INCLUDED
#define LEVELSCREEN_H_INCLUDED

#include "Screens/Screen.h"


class LevelScreen : public Screen
{
public:
    LevelScreen(Game* game, bool blockE, bool blockU, bool blockR);
    void init() override;
    void processEvents() override;
    void update() override;
    void render() override;
};

#endif // LEVELSCREEN_H_INCLUDED
