
#include "Tclient.h"
#include "../tools.h"
#include <string>
#include <unistd.h>
#include <cstring>


void Tclient::send(const std::string &string) const {
     tools::send(sock, string);
}


std::string Tclient::recv() const {
    return tools::recv(sock);
}

void Tclient::close() const {
    ::close(this->sock);
}

Tclient::Tclient(in_addr_t ip, in_port_t port) : sock(socket(AF_INET, SOCK_STREAM, 0)), sin() {
    //Initialize the socket and check it
    if (sock < 0) {
        perror("error creating socket");
    }
    //Initialize the data structure
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = ip;
    sin.sin_port = port;
    //Connect to the Server
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to Server");
    }
}