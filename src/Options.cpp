#include "Options.h"
#include <SFML/VideoMode.hpp>

Options::Options()
{
	fullscreen = true;
	VideoMode res = VideoMode::getDesktopMode();
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
		optionsFile.getline(line);

		size_t pos = line.find(":");
		std::string option = line.substr(0, pos);
		std::string value = line.substr(pos + 1, line.size());

		switch (option)
		{
		case "full":
			switch (value)
			{
			case "true":
				fullscreen = true;
				break;
			case "false":
				fullscreen = false;
				break;
			default:
				break;
			}
			break;
		case "resX":
			resX = std::atoi(value);
			break;
		case "resY":
			resY = std::atoi(value);
			break;
		}
	}

	optionsFile.close();
}

void Options::save()
{
	optionsFile.open(fileName, std::fstream::out | std::fstream::trunc);

	optionsFile << "fullscreen:";
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
