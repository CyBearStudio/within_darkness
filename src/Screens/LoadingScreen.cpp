#include "Screens/LoadingScreen.h"
#include <utility>


LoadingScreen::LoadingScreen(Game* game, bool blockE, bool blockU, bool blockR) : Screen(game, blockE, blockU, blockR), mTaskCount(0)
{
}

void LoadingScreen::ProcessEvents() 
{
    
}

void LoadingScreen::update() 
{
    
}

void LoadingScreen::render() 
{
    
}

void LoadingScreen::registerTask(Task& task)
{
    std::unique_ptr<Task> task_ptr(&task);
    mTaskQueue.push(std::move(task_ptr));

    mTaskCount = mTaskQueue.size();
}
