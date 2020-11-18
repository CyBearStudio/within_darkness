#include "Game.h"
#include "Version.h"


Game::Game() : mLogger("latestlog.txt"), mOptions(&mLogger)
{
    // storing version number for later use
	version = std::to_string(PROJECT_VERSION_MAJOR) + "." + std::to_string(PROJECT_VERSION_MINOR) + "." + std::to_string(PROJECT_VERSION_PATCH);
}

void Game::init()
{
	mLogger.log("Initialized game", LOG::INFO);

	mLogger.log("Within Darkness client version " + version, LOG::INFO);
    
    // creating splash screen
	mWindow.create(sf::VideoMode(640, 480), "Within Darkness " + version, sf::Style::None);
	sf::VideoMode dMode = sf::VideoMode::getDesktopMode();
	mWindow.setPosition(sf::Vector2i((dMode.width / 2) - 320, (dMode.height / 2) - 240));
    
    // loading font
    if (!mFont.loadFromFile("res/font/Roboto-Regular.ttf"))
    {
        mLogger.log("Missing file res/font/Roboto-Regular.ttf", LOG::ERROR);
        
        mLogger.log("Stoping!", LOG::ERROR);
		exit(EXIT_FAILURE);
    }
    mLogger.log("Loaded file res/font/Roboto-Regular.ttf", LOG::INFO);
    sf::Text versionText("version " + version, mFont);
    versionText.setFillColor(sf::Color(255, 255, 255));
    
    // loading splash
	sf::Texture splashTexture;
	if (!splashTexture.loadFromFile("res/splash.png"))
	{
		mLogger.log("Missing file res/splash.png", LOG::ERROR);
        
        mLogger.log("Stoping!", LOG::ERROR);
		exit(EXIT_FAILURE);
	}
	mLogger.log("Loaded file res/splash.png", LOG::INFO);
	sf::Sprite splashSprite;
	splashSprite.setTexture(splashTexture);

    // rendering splash screen
	mWindow.draw(splashSprite);
    mWindow.draw(versionText);
	mWindow.display();
    
	mLogger.log("Showed splash screen", LOG::INFO);
    
    // loading options from file
    mOptions.load("options.txt");
    
    // saving options to complete the file
    mOptions.save();

    // leaving splash screen for 2 seconds for style
	sf::sleep(sf::seconds(2.f));
    
    // re-creating the main window to display game
    mWindow.create(mOptions.getVideoMode(), "Within Darkness " + version, mOptions.getStyle());
    
    sf::Texture studioTexture;
    if (!studioTexture.loadFromFile("res/studiologo.png"))
    {
        mLogger.log("Missing file res/studiologo.png", LOG::ERROR);
        
        mLogger.log("Stoping!", LOG::ERROR);
        exit(EXIT_FAILURE);
    }
    mLogger.log("Loaded file res/studiologo.png", LOG::INFO);
    sf::Sprite studioSprite;
    studioSprite.setTexture(studioTexture);
    studioSprite.setPosition((mWindow.getSize().x / 2) - 256.f, (mWindow.getSize().y / 2) - 256.f);
    
    sf::Text statText;
    statText.setFont(mFont);
    statText.setFillColor(sf::Color(255, 255, 255));
    
    mLogger.log("Loaded start screen", LOG::INFO);
    
    // rendering first game frame
    mWindow.clear(sf::Color(30, 30, 30));
    mWindow.draw(studioSprite);
    mWindow.display();
    
    mLogger.log("Lunched game", LOG::INFO);
    
    bool startScreen = true;
    sf::Time elapsedTime;
    mClock.restart();
    
    // main game loop: will be in run() next patch
    while (startScreen)
    {
        sf::Event event;
        while (mWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                startScreen = false;
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                startScreen = false;
            }
        }
        
        // calculating frame rate
        elapsedTime = mClock.restart();
        float fps = 1 / elapsedTime.asSeconds();
        statText.setString("version " + version + "; fps: " + std::to_string(int(fps)));
        
        // rendering start screen
        mWindow.clear(sf::Color(30, 30, 30));
        mWindow.draw(studioSprite);
        mWindow.draw(statText);
        mWindow.display();
    }
}

void Game::run()
{
    mLogger.log("Stoping!", LOG::INFO);
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

Logger& Game::getLogger()
{
    return mLogger;
}
