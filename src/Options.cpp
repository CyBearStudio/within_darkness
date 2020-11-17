#include "Options.h"


Options::Options()
{
	// default values
	fullscreen = true;
	sf::VideoMode res = sf::VideoMode::getDesktopMode(); // based on desktop size
	resX = res.width;
	resY = res.height;
}

void Options::load(const std::string& lf)
{
	// opening file in read mode
	fileName = lf;
	optionsFile.open(fileName, std::fstream::in);

	// reading each line in file
	std::string line;
	while (optionsFile.good())
	{
		std::getline(optionsFile, line);

		// parsing line
		size_t pos = line.find(":");
		std::string option = line.substr(0, pos);
		std::string value = line.substr(pos + 1, line.size());

		// determining setting and assigning value
		if (option == "full")
		{
			if (value == "true")
			{
				fullscreen = true;
			}
			else if (value == "false")
			{
				fullscreen = false;
			}
		}
		else if (option == "resX")
		{
			resX = std::stoi(value);
		}
		else if (option == "resY")
		{
			resY = std::stoi(value);
		}
	}

	// closing file to free memory
	optionsFile.close();
}

void Options::save()
{
	// overwriting file
	optionsFile.open(fileName, std::fstream::out | std::fstream::trunc);

	// writing settings and value in alphabetical order
	optionsFile << "full:";
	if (fullscreen)
	{
		optionsFile << "true";
	}
	else
	{
		optionsFile << "false";
	}
	optionsFile << std::endl;

	optionsFile << "resX:" << std::to_string(resX) << std::endl;

	optionsFile << "resY:" << std::to_string(resY) << std::endl;
}

sf::VideoMode Options::getVideoMode()
{
    return sf::VideoMode(resX, resY);
}

sf::Uint32 Options::getStyle()
{
    if (fullscreen)
    {
        return sf::Style::Fullscreen;
    }
    return sf::Style::Default;
}


