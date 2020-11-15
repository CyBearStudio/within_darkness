#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED

#include <fstream>
#include <SFML/Window.hpp>


class Options
{
public:
	Options();
	void load(std::string lf);
	void save();

private:
	std::fstream optionsFile;
	std::string fileName;
	bool fullscreen;
	unsigned int resX;
	unsigned int resY;
    
public:
    sf::VideoMode getVideoMode();
    sf::Uint32 getStyle();
};

#endif // OPTIONS_H_INCLUDED
