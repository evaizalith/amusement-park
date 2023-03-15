//log.hpp
//This file contains declarations for the Log class.
//The Log class is used to handle logging debug info and errors. 

#include <iostream>
#include <vector>

#ifndef GL2_LIB_LOG
#define GL2_LIB_LOG

class Log {
public:
    Log(int log_level) { log_verbosity = log_level; };
    ~Log();

    //Pass array or vector of strings to both methods
    //If logging is verbose [log_verbosity = 2], all strings will be printed
    //If logging is normal [log_verbosity = 1], only index 0 will be printed
    void log_info(std::vector<std::string>);
    void log_error(std::vector<std::string>);
    void log_fatal(std::vector<std::string>);

    void log_info(std::string);
    void log_error(std::string);
    void log_fatal(std::string);
private:
    int log_verbosity;
};

#endif