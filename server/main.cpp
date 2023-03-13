#include <iostream>
#include <algorithm> 
#include "lib/tcp_server.hpp"

bool ifArgExists(char** begin, char **end, const std::string& option) {
    return std::find(begin, end, option) != end;
}

int main(int argc, char** argv) {
    std::cout << "Hello world" << std::endl;

    int logging;
    if(ifArgExists(argv, argc+argv, "-v")) {
        logging = 2; //Verbose logging 
    } else if (ifArgExists(argv, argc+argv, "-l")) {
        logging = 1; //Normal logging
    } else {
        logging = 0; //No logging 
    }

    TCPServer server = TCPServer("127.0.0.1", 1917, logging);

    server.closeServer();

    return 0;
}