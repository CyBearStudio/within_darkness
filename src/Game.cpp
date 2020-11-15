#include "Game.h"
#include "Version.h"


Game::Game() : mLogger("latestlog.txt"), mOptions()
{
    // storing version number for later use
	version = std::to_string(PROJECT_VERSION_MAJOR) + "." + std::to_string(PROJECT_VERSION_MINOR) + "." + std::to_string(PROJECT_VERSION_PATCH);
}

void Game::init()
{
	mLogger.log("Initializing game ...");

	mLogger.log("Within Darkness client version " + version);

	mLogger.log("Loading splash screen ...");
    
    // creating splash screen
	mWindow.create(sf::VideoMode(640, 480), "Within Darkness " + version, sf::Style::None);
	sf::VideoMode dMode = sf::VideoMode::getDesktopMode();
	mWindow.setPosition(sf::Vector2i((dMode.width / 2) - 320, (dMode.height / 2) - 240));
    if (!mFont.loadFromFile("res/font/Roboto-Regular.ttf"))
    {
        mLogger.log("ERROR: missing res/font/Roboto-Regular.ttf");
        
        mLogger.log("Program terminated with ERROR");
		exit(EXIT_FAILURE);
    }
    sf::Text versionText("version " + version, mFont);
    versionText.setFillColor(sf::Color(255, 255, 255));
	sf::Texture splashTexture;
	if (!splashTexture.loadFromFile("res/splash.png"))
	{
		mLogger.log("ERROR: missing res/splash.png");
        
        mLogger.log("Program terminated with ERROR");
		exit(EXIT_FAILURE);
	}
	sf::Sprite splashSprite;
	splashSprite.setTexture(splashTexture);

    // rendering splash screen
	mWindow.draw(splashSprite);
    mWindow.draw(versionText);
	mWindow.display();
    
	mLogger.log("Showing splash screen done");
    
    mLogger.log("Loading options ...");
    
    // loading options from file
    mOptions.load("options.txt");
    
    mLogger.log("Loading options done");
    
    mLogger.log("Saving options ...");
    
    // saving options to complete the file
    mOptions.save();
    
    mLogger.log("Saving options done");

    // leaving splash screen for 2 seconds for style
	sf::sleep(sf::seconds(2.f));
    
    mLogger.log("Lunching game ...");
    
    mLogger.log("Loading start screen ...");
    
    // re-creating the main window to display game
    mWindow.create(mOptions.getVideoMode(), "Within Darkness " + version, mOptions.getStyle());
    sf::Texture studioTexture;
    if (!studioTexture.loadFromFile("res/studiologo.png"))
    {
        mLogger.log("ERROR: missing res/studiologo.png");
        
        mLogger.log("Program terminated with ERROR");
        exit(EXIT_FAILURE);
    }
    sf::Sprite studioSprite;
    studioSprite.setTexture(studioTexture);
    studioSprite.setPosition((mWindow.getSize().x / 2) - 256, (mWindow.getSize().y / 2) - 256);
    sf::Text statText;
    statText.setFont(mFont);
    statText.setFillColor(sf::Color(255, 255, 255));
    
    mLogger.log("Loading start screen done");
    
    // rendering first game frame
    mWindow.clear(sf::Color(30, 30, 30));
    mWindow.draw(studioSprite);
    mWindow.display();
    
    mLogger.log("Lunching game done");
    
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
