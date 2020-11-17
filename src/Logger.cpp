#include"Logger.h"


Logger::Logger(const std::string& lf)
{
    logfile.open(lf, std::fstream::out | std::fstream::trunc); // file is automatically closed when object is destructed
}

void Logger::log(const std::string& str)
{
    logfile << str << std::endl; // line break
    std::cout << str << std::endl; // line break
}
