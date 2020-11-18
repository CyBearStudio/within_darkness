#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

#include<fstream>


class Logger
{
public:
    Logger(const std::string& lf); // link logger to lf file
    void log(const std::string& str); // append str to log file and print it in console
    
private:
    std::ofstream logfile; // latestlog.txt
};


#endif // LOGGER_H_INCLUDED
