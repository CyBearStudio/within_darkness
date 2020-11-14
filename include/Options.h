#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED

#include <fstream>


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
};

#endif // OPTIONS_H_INCLUDED
