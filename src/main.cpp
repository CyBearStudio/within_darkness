
#include <SFML/Graphics.hpp>
#include "Logger.h"
#include "Game.h"

int main()
{
    Game game;

    game.init();
    game.run();

    return 0;
}
