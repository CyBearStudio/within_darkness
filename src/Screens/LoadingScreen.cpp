#include "Screens/LoadingScreen.h"


LoadingScreen::LoadingScreen(Game* game, bool blockE, bool blockU, bool blockR) : Screen(game, blockE, blockU, blockR)
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

template<typename Identifier>
void LoadingScreen::register(Identifier id, const std::string& filename) 
{
    mTaskQueue.push(std::make_pair(id, filename));
    mTaskCount = mTaskQueue.size();
}
