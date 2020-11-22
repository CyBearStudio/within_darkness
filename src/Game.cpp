#include "Game.h"
#include "Version.h"
#include <math.h>


Game::Game() : mIsRunning(true), mLogger("latestlog.txt"), mOptions(&mLogger), mTimePerFrame(sf::Time::Zero)
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
}

void Game::run()
{
    mLogger.log("Lunched game", LOG::INFO);

    // objects to handle frame rate
    sf::Clock clock;
    sf::Time timeSinceLastRender(sf::Time::Zero);
    
    // deltaTime between updates
    sf::Time elapsedTime(sf::Time::Zero);

    // main loop
    while (mIsRunning)
    {
        // update game state
        processEvents();
        update();

        // update time since last render
        elapsedTime = clock.restart();
        timeSinceLastRender += elapsedTime;

        // render if fps limit is not reached
        if(timeSinceLastRender >= mTimePerFrame)
        {
            render();
            timeSinceLastRender = sf::Time::Zero;
        }
    }

    mLogger.log("Stoping!", LOG::INFO);
}

void Game::quit() 
{
    mIsRunning = false;
}

void Game::processEvents()
{
    // event processing of title screen
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            mIsRunning = false;
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            mIsRunning = false;
        }
    }
}

void Game::update()
{
}

void Game::render()
{
    // calculating frame rate
    sf::Time elapsedTime = mFPSClock.restart();
    float fps = 1 / elapsedTime.asSeconds();

    // rendering title screen
    mWindow.clear(sf::Color(30, 30, 30));

    // initializing stat text to display version and fps
    sf::Text statText;
    statText.setFont(mFont);
    statText.setFillColor(sf::Color(255, 255, 255));
    statText.setString("version " + version + "; fps: " + std::to_string(int(fps)));

    // initializing title text
    sf::Text titleText("Within Darkness", mFont, 90);
    titleText.setFillColor(sf::Color(255, 255, 255));
    titleText.setOrigin(titleText.getLocalBounds().width / 2, titleText.getLocalBounds().height / 2);
    titleText.setPosition(mWindow.getSize().x / 2, mWindow.getSize().y / 2);

    // initializing "Press a key" text
    sf::Text infoText("Press a key to continue", mFont);
    infoText.setFillColor(sf::Color(255, 255, 255, 122 * cos(2 * mAlphaClock.getElapsedTime().asSeconds()) + 123));
    infoText.setOrigin(infoText.getLocalBounds().width / 2, infoText.getLocalBounds().height / 2);
    infoText.setPosition(mWindow.getSize().x / 2, 3 * (mWindow.getSize().y / 4));

    // rendering assets
    mWindow.draw(statText);
    mWindow.draw(titleText);
    mWindow.draw(infoText);
    mWindow.display();
}

Logger& Game::getLogger()
{
    return mLogger;
}
