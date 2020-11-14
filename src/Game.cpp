#include "Game.h"
#include "Version.h"


Game::Game() : mLogger("latestlog.txt"), mOptions()
{
	version = std::to_string(PROJECT_VERSION_MAJOR) + "." + std::to_string(PROJECT_VERSION_MINOR) + "." + std::to_string(PROJECT_VERSION_PATCH);
}

void Game::init()
{
	mLogger.log("Initializing game ...");

	mLogger.log("Within Darkness client version " + version);

	mLogger.log("Showing splash screen ...");
	mWindow.create(sf::VideoMode(640, 480), "Within Darkness " + version, sf::Style::None);
	sf::VideoMode dMode = sf::VideoMode::getDesktopMode();
	mWindow.setPosition(sf::Vector2i((dMode.width / 2) - 320, (dMode.height / 2) - 240));
	sf::Texture splashTexture;
	if (!splashTexture.loadFromFile("res/splash.png"))
	{
		mLogger.log("ERROR: missing res/splash.png");
		exit(EXIT_FAILURE);
	}
	sf::Sprite splashSprite;
	splashSprite.setTexture(splashTexture);
	mWindow.draw(splashSprite);
	mWindow.display();
	mLogger.log("Showing splash screen done");

	sf::sleep(sf::seconds(2.f));
}

void Game::run()
{
}

void Game::processEvents()
{
}

void Game::update()
{
}

void Game::render()
{
}
