#ifndef LOADINGSCREEN_H_INCLUDED
#define LOADINGSCREEN_H_INCLUDED

#include "Screen.h"
#include <queue>
#include <memory>
#include "Misc/LoadingTask.h"


class LoadingScreen : public Screen
{
public:
    LoadingScreen(Game* game, bool blockE, bool blockU, bool blockR);
    void ProcessEvents();
    void update();
    void render();
    void registerTask(Task& task);

private:
    std::queue<std::unique_ptr<Task>> mTaskQueue;
    int mTaskCount;
};

#endif // LOADINGSCREEN_H_INCLUDED
