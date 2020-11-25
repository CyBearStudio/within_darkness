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
    void init(); // inherited
    void ProcessEvents(); // inherited
    void update(); // inherited
    void render(); // inherited
    void registerTask(Task& task); // register a new task to be processed

private:
    std::queue<std::unique_ptr<Task>> mTaskQueue; // task holder with FIFO structure
    int mTaskCount; // number of registered tasks to process
};

#endif // LOADINGSCREEN_H_INCLUDED
