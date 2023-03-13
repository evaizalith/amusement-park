//tcp_server.hpp
//This contains all declarations for the API used by the server 

#include <iostream>
#include <thread>
#include <vector>

#ifndef GL2_LIB_TCPSERV
#define GL2_LIB_TCPSERV

class TCPServer {
public:
    TCPServer(std::string address, int port, int log_verbosity);
    ~TCPServer();

    void closeServer();

private:
    std::string address;
    int port;
    std::vector<std::thread> threads; 
};

#endif 