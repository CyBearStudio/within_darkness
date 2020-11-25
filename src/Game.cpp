#include "Game.h"
#include "Version.h"
#include "GlobalResource.h"
#include <math.h>


Game::Game() : mIsRunning(true), mLogger(GlobalResource::FILE_LOG), mOptions(&mLogger), mTimePerFrame(sf::Time::Zero)
{
    // storing version number for later use
	mVersion = std::to_string(PROJECT_VERSION_MAJOR) + "." + std::to_string(PROJECT_VERSION_MINOR) + "." + std::to_string(PROJECT_VERSION_PATCH);
}

void Game::init()
{
	mLogger.log(GlobalResource::LOG_INIT, LOG::INFO);

	mLogger.log(GlobalResource::LOG_VERSION + mVersion, LOG::INFO);
    
    // creating splash screen
	mWindow.create(sf::VideoMode(640, 480), GlobalResource::WINDOW_TITLE + mVersion, sf::Style::None);
	sf::VideoMode dMode = sf::VideoMode::getDesktopMode();
	mWindow.setPosition(sf::Vector2i((dMode.width / 2) - 320, (dMode.height / 2) - 240));
    
    // loading font
    if (!mFont.loadFromFile(GlobalResource::FONT_MAIN))
    {
        mLogger.log(GlobalResource::LOG_MISSING + GlobalResource::FONT_MAIN, LOG::ERROR);
        
        mLogger.log(GlobalResource::LOG_STOP, LOG::ERROR);
		exit(EXIT_FAILURE);
    }
    mLogger.log(GlobalResource::LOG_LOADED + GlobalResource::FONT_MAIN, LOG::INFO);
    sf::Text versionText(GlobalResource::STAT_VERSION + mVersion, mFont);
    versionText.setFillColor(sf::Color::White);
    
    // loading splash
	sf::Texture splashTexture;
	if (!splashTexture.loadFromFile(GlobalResource::TEX_SPLASH))
	{
		mLogger.log(GlobalResource::LOG_MISSING + GlobalResource::TEX_SPLASH, LOG::ERROR);
        
        mLogger.log(GlobalResource::LOG_STOP, LOG::ERROR);
		exit(EXIT_FAILURE);
	}
	mLogger.log(GlobalResource::LOG_LOADED + GlobalResource::TEX_SPLASH, LOG::INFO);
	sf::Sprite splashSprite;
	splashSprite.setTexture(splashTexture);

    // rendering splash screen
	mWindow.draw(splashSprite);
    mWindow.draw(versionText);
	mWindow.display();
    
	mLogger.log(GlobalResource::LOG_SPLASH, LOG::INFO);
    
    // loading options from file
    mOptions.load(GlobalResource::FILE_CONFIG);
    
    // saving options to complete the file
    mOptions.save();

    // leaving splash screen for 2 seconds for style
	sf::sleep(sf::seconds(2.f));
    
    // re-creating the main window to display game
    mWindow.create(mOptions.getVideoMode(), GlobalResource::WINDOW_TITLE + mVersion, mOptions.getStyle());
}

void Game::run()
{
    mLogger.log(GlobalResource::LOG_RUN, LOG::INFO);

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

    mLogger.log(GlobalResource::LOG_STOP, LOG::INFO);
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
    statText.setString(GlobalResource::STAT_VERSION + mVersion + "; " + GlobalResource::STAT_FPS + std::to_string(int(fps)));

    // initializing title text
    sf::Text titleText(GlobalResource::TEXT_TITLE, mFont, 90);
    titleText.setFillColor(sf::Color(255, 255, 255));
    titleText.setOrigin(titleText.getLocalBounds().width / 2, titleText.getLocalBounds().height / 2);
    titleText.setPosition(mWindow.getSize().x / 2, mWindow.getSize().y / 2);

    // initializing "Press a key" text
    sf::Text infoText(GlobalResource::TEXT_CONTINUE, mFont);
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
