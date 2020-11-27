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
    void init() override;
    void processEvents() override;
    void update() override;
    void render() override;
    void registerTask(Task& task); // register a new task to be processed

private:
    std::queue<std::unique_ptr<Task>> mTaskQueue; // task holder with FIFO structure
    int mTaskCount; // number of registered tasks to process
};

#endif // LOADINGSCREEN_H_INCLUDED
