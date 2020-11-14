#include"logger.h"


Logger::Logger(std::string lf)
{
    logfile.open(lf); // file is automatically closed when object is destructed
}

void Logger::log(std::string str)
{
    logfile << str << '\n' ; // line break
    std::cout<<str<<std::endl; // line break
}
