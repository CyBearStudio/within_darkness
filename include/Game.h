#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED


class Game
{
public:
	Game();
	void init();
	void run();

private:
	void processEvents();
	void update();
	void render();

private:
	sf::RenderWindow mWindow;
};


#endif // GAME_H_INCLUDED
