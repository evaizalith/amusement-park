#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "tcp_server.hpp"
#include "log.hpp"

const int BUFFER_SIZE = 1024;

TCPServer::TCPServer(std::string _address, int _port, int _logging) {
    address = _address;
    port = _port;
    logger = new Log(_logging); 

    logger->log_info("Created new server.");
}

TCPServer::~TCPServer() {
    closeServer();
}

int TCPServer::startServer() {
    m_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(m_socket < 0) {
        logger->log_fatal("FAILED TO OPEN SOCKET");
        return 1;
    }

    if(bind(m_socket, (sockaddr *)&socketAddress, socketAddress_len) < 0) {
        logger->log_fatal("FAILED TO BIND SOCKET TO ADDRESS");
        return 1;
    }

    logger->log_info("Starting server...");

    return 0;
}

void TCPServer::closeServer() {
    close(m_socket);
    close(new_socket);

    logger->log_info("Server shutting down.");
    delete logger;
}

void TCPServer::startListen() {
    if (listen(m_socket, 20) < 0) {
        logger->log_fatal("SOCKET LISTEN FAILED");
        return; 
    }

    //Logging 
    std::vector<std::string> listenInfo;
    listenInfo.push_back("Socket started listening successfully.");
    listenInfo.push_back("Listening on address: ");
    listenInfo[1] += inet_ntoa(socketAddress.sin_addr);
    listenInfo.push_back("Port: ");
    listenInfo[2] += ntohs(socketAddress.sin_port);
    logger->log_info(listenInfo);

    int bytesReceived;

    while (true) {
        acceptConnection(new_socket);

        char buffer[BUFFER_SIZE];
        bytesReceived = read(new_socket, buffer, BUFFER_SIZE);

        if(bytesReceived < 0) {
            std::vector<std::string> error; 
            error.push_back("Failed to read bytes from client socket");
            error.push_back("Bad client socket: ");
            error[1] += new_socket;
            logger->log_error(error);
        }

        logger->log_info("Received request from client");

        sendResponse();

        close(new_socket);
    }
}

void TCPServer::acceptConnection(int &acpt_new_socket) {
    acpt_new_socket = accept(new_socket, (sockaddr *)&socketAddress, &socketAddress_len);
    if(acpt_new_socket < 0) {
        std::string error = "Failed to accept incoming connection from: ";
        error += inet_ntoa(socketAddress.sin_addr);
        error += " : ";
        error += ntohs(socketAddress.sin_port);
        logger->log_error(error);
    }
}

std::string TCPServer::buildResponse() {
    //NEED TO IMPLEMENT A CLASS THAT HANDLES HTML PAGES
    std::string html = "<!DOCTYPE html> <html> <head> <title> Geauga Lake 2 </title> </head> <body> <h1> Geauga Lake 2 </h1> <p> Prepare for the time of your life.</p></body></html>";
    html += "HTTP/1.1 200 OK\nContent-Type: text/htl\n";
    return html;
}

void TCPServer::sendResponse() {
    long bytesSent;

    std::string serverMessage = buildResponse();
    bytesSent = write(new_socket, serverMessage.c_str(), serverMessage.size());

    if(bytesSent == serverMessage.size()) {
        logger->log_info("Sent response to client");
    } else {
        logger->log_error("Error sending response to client");
    }
}

