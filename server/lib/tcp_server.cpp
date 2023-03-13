#include <iostream>
#include <vector>
#include <thread>
#include "tcp_server.hpp"
#include "log.hpp"

TCPServer::TCPServer(std::string _address, int _port, int _logging) {
    address = _address;
    port = _port;
    logger = new Log(_logging); 
}

TCPServer::~TCPServer() {
    delete logger;
}

int TCPServer::startServer() {
    
}

void TCPServer::closeServer() {
    delete this; 
}