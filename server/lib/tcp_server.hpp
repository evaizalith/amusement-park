//tcp_server.hpp
//This contains all declarations for the API used by the server 

#include <iostream>
#include <thread>
#include <vector>
#include "log.hpp"
#include <sys/socket.h>
#include <arpa/inet.h>

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
    int m_socket;
    int new_socket;

    long incoming_message;
    struct sockaddr_in socketAddress;
    unsigned int socketAddress_len;

    Log *logger;

    //Private Functions
    void startListen();
    void acceptConnection(int &acpt_new_socket);
    std::string buildResponse();
    void sendResponse(); 
};

#endif 