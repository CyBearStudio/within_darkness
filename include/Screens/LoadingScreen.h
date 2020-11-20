#ifndef LOADINGSCREEN_H_INCLUDED
#define LOADINGSCREEN_H_INCLUDED

#include "Screen.h"
#include <queue>
#include <utility>


class LoadingScreen : public LoadingScreen
{
public:
    LoadingScreen(Game* game, bool blockE, bool blockU, bool blockR);
    void ProcessEvents();
    void update();
    void render();
    template<typename Identifier>
    void register(Identifier id, const std::string& filename);

private:
    std::queue<std::pair> mTaskQueue;
    int mTaskCount;
};

#endif // LOADINGSCREEN_H_INCLUDED
