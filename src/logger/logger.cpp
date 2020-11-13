//Logger class:
#include<iostream>
#include<fstream>


class Logger{

public:
    Logger(std::string lf):filename(lf){};
    void log(std::string str);
    
private:
    std::ofstream logfile;
    std::string filename;
};

void Logger::log(std::string str){
    logfile.open(filename, std::ios::app);
    logfile << str << '\n' ;
    logfile.close();
    
    
    std::cout<<str<<std::endl;
}



