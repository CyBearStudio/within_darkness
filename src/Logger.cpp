#include"Logger.h"
#include <iostream>
#include <ctime>
#include <iomanip>


Logger::Logger(const std::string& lf)
{
    logfile.open(lf, std::fstream::out | std::fstream::trunc); // file is automatically closed when object is destructed
}

void Logger::log(const std::string& str)
{
    time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);

    logfile << "[" << std::put_time(&tm, "%T") << "]: " << str << std::endl; // line break
    std::cout << "[" << std::put_time(&tm, "%T") << "]: " << str << std::endl; // line break
}
