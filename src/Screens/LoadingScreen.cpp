#include "Screens/LoadingScreen.h"
#include <utility>


LoadingScreen::LoadingScreen(Game* game, bool blockE, bool blockU, bool blockR) : Screen(game, blockE, blockU, blockR), mTaskCount(0)
{
}

void LoadingScreen::init() 
{
    
}

void LoadingScreen::processEvents() 
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
    // creating new task and adding it to container
    std::unique_ptr<Task> task_ptr(&task);
    mTaskQueue.push(std::move(task_ptr));

    // updating registered tasks count
    mTaskCount = mTaskQueue.size();
}
