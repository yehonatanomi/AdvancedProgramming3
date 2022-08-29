#include "SocketIO.h"
#include "string"
#include "../tools.h"
#include <unistd.h>

SocketIO::SocketIO(int socket) : socket(socket) {}

std::string SocketIO::read() {
    return tools::recv(this->socket);
}

void SocketIO::send(std::string msg) {
    tools::send(this->socket, msg);
}

SocketIO::~SocketIO() {
    close(this->socket);
}