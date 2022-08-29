//
// Created by yehonatan on 8/29/2022.
//

#include "Tserver.h"
#include <unistd.h>
#include "cstring"

Tserver::Tserver(in_addr_t ip, in_port_t port) : sockId(socket(AF_INET, SOCK_STREAM, 0)), from() {
    //Initialize the socket and check it
    if (sockId < 0) {
        perror("error creating socket");
    }
    //Initialize the data structure
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = ip;
    sin.sin_port = port;
    //Bind the socket to the port and ip
    if (bind(sockId, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
    if (listen(sockId, this->queueLen) < 0) {
        perror("error listening to a socket");
    }

    memset(&tv, 0, sizeof(tv));
    // Timeout in seconds
    tv.tv_sec = 270;

    FD_ZERO(&readfds);
    FD_SET(sockId, &readfds);
}


int Tserver::accept() {
    if (select(sockId + 1, &readfds, nullptr, nullptr, &tv) < 0) {
        perror("select error");
    }
    // If a connection has been made to connect to the Server, and the Timeout hasn't passed yet
    if (FD_ISSET(sockId, &readfds)) {
        unsigned int addr_len = sizeof(this->from);
        int sock = ::accept(sockId, (struct sockaddr *) &from, &addr_len);
        if (sock < 0) {
            perror("error accepting Client");
        }
        this->clientNum++;
        return sock;
    }
    return -1;
}

void Tserver::close() const {
    //Close the socket
    ::close(this->sockId);

}

void Tserver::disconnectClient() {
    this->clientNum--;
}

int Tserver::getClientNum() const {
    return this->clientNum;
}