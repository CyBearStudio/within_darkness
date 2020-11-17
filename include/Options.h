#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED

#include <fstream>
#include <SFML/Window.hpp>


class Options
{
public:
	Options(); // initializing settings with default values
	void load(const std::string& lf); // retrieving settings values from file
	void save(); // saving settings values in file

private:
	std::fstream optionsFile; // options.txt
	std::string fileName; // for saving later
	bool fullscreen; // desired window style
	unsigned int resX; // desired window width
	unsigned int resY; // desired window height
    
public:
    sf::VideoMode getVideoMode(); // returns desired video mode based on resX and resY
    sf::Uint32 getStyle(); // returns desired window style based on fullscreen value
};

#endif // OPTIONS_H_INCLUDED
