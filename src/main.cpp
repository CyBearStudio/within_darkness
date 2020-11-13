
#include <SFML/Graphics.hpp>
#include "Version.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Within Darkness version "+std::to_string(PROJECT_VERSION_MAJOR)+"."+std::to_string(PROJECT_VERSION_MINOR)+"."+std::to_string(PROJECT_VERSION_PATCH));
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
