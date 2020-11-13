#include"../include/logger.h"


Logger::Logger(std::string lf){
    logfile.open(lf);
}

void Logger::log(std::string str){
    logfile << str << '\n' ;    
    std::cout<<str<<std::endl;
}
