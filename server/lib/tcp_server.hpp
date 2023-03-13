//tcp_server.hpp
//This contains all declarations for the API used by the server 

#include <iostream>
#include <thread>
#include <vector>
#include "log.hpp"

#ifndef GL2_LIB_TCPSERV
#define GL2_LIB_TCPSERV

class TCPServer {
public:
    TCPServer(std::string address, int port, int log_verbosity);
    ~TCPServer();

    int startServer();
    void closeServer();

private:
    std::string address;
    int port;
    std::vector<std::thread> threads; 

    Log *logger; 
};

#endif 