#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

#include<iostream>
#include<fstream>


class Logger{
public:
    Logger(std::string lf);
    void log(std::string str);
    
private:
    std::ofstream logfile;
};


#endif // LOGGER_H_INCLUDED
