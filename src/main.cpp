
#include <SFML/Graphics.hpp>
#include "Logger.h"
#include "Game.h"

int main()
{
    Game game; // creating a new game object

    game.init(); // initializing the game
    game.run(); // running the game

    return 0;
}
