#include <iostream>
#include <vector>
#include "log.hpp"

void Log::log_info(std::vector<std::string> input) {
    if(log_verbosity == 1) {
        std::cout << input.at(0) << std::endl;
    } else if(log_verbosity == 2) {
        for(int i = 0; i < input.size(); i++) {
            std::cout << input.at(i) << std::endl; 
        }
    }
}

void Log::log_error(std::vector<std::string> input) {
    if(log_verbosity == 1) {
        std::cout << "ERROR: " << input.at(0) << std::endl;
    } else if(log_verbosity == 2) {
        for(int i = 0; i < input.size(); i++) {
            std::cout << "ERROR: " << input.at(i) << std::endl; 
        }
    }
}

void Log::log_fatal(std::vector<std::string> input) {
    if(log_verbosity == 1) {
        std::cout << "FATAL ERROR: " << input.at(0) << std::endl;
    } else if(log_verbosity == 2) {
        for(int i = 0; i < input.size(); i++) {
            std::cout << "FATAL ERROR: " << input.at(i) << std::endl; 
        }
    }
}