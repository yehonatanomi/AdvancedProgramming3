#include <string>
#include <unistd.h>
#include <cstring>
#include "TClient.h"
#include "../tools.h"

void TClient::send(const std::string &string) const {
    utils::send(sock, string);
}


std::string TClient::recv() const {
    return utils::recv(sock);
}

void TClient::close() const {
    ::close(this->sock);
}

TClient::TClient(in_addr_t ip, in_port_t port) : sock(socket(AF_INET, SOCK_STREAM, 0)), sin() {
    if (sock < 0) {
        perror("error creating socket");
    }
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = ip;
    sin.sin_port = port;
    //Connect  the server
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
}

