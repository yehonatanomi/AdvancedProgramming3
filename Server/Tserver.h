#include <netinet/in.h>
#include "string"

#ifndef CLIENT_TCPSERVER_H
#define CLIENT_TCPSERVER_H

class TServer {
private:
    int sockId;
    int queueLen = 5;
    int clientNum = 0;
    struct sockaddr_in from;
    fd_set readfds;
    struct timeval tv;
public:
    TServer(in_addr_t ip, in_port_t port);

    int accept();

    void close() const;

    ~TServer() = default;

    void disconnectClient();

    int getClientNum() const;
};


#endif //CLIENT_TCPSERVER_H
