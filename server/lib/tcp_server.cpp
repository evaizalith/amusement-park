#include <iostream>
#include <vector>
#include <thread>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "tcp_server.hpp"
#include "log.hpp"

TCPServer::TCPServer(std::string _address, int _port, int _logging) {
    address = _address;
    port = _port;
    logger = new Log(_logging); 
}

TCPServer::~TCPServer() {
    closeServer();
}

int TCPServer::startServer() {
    m_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(m_socket < 0) {
        std::string error = "FAILED TO OPEN SOCKET";
        logger->log_fatal(error);
        return 1;
    }

    return 0;
}

void TCPServer::closeServer() {
    close(m_socket);
    delete logger;
}