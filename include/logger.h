#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

#include<iostream>
#include<fstream>


class Logger{
public:
    Logger(std::string lf); // link logger to lf file
    void log(std::string str); // append str to log file and print it in console
    
private:
    std::ofstream logfile; // latestlog.txt
};


#endif // LOGGER_H_INCLUDED
