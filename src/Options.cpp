#include "Options.h"


Options::Options()
{
	fullscreen = true;
	sf::VideoMode res = sf::VideoMode::getDesktopMode();
	resX = res.width;
	resY = res.height;
}

void Options::load(std::string lf)
{
	fileName = lf;
	optionsFile.open(fileName, std::fstream::in);

	std::string line;
	while (optionsFile.good())
	{
		std::getline(optionsFile, line);

		size_t pos = line.find(":");
		std::string option = line.substr(0, pos);
		std::string value = line.substr(pos + 1, line.size());

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

	optionsFile.close();
}

void Options::save()
{
	optionsFile.open(fileName, std::fstream::out | std::fstream::trunc);

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


