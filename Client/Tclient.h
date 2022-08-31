#ifndef CLIENT_TCPCLIENT_H
#define CLIENT_TCPCLIENT_H

#include <netinet/in.h>
#include "string"

class TClient {
private:
    int sock;
    struct sockaddr_in sin;
public:
    void send(const std::string &) const;

    std::string recv() const;

    void close() const;

    TClient(in_addr_t, in_port_t);

    ~TClient() = default;
};


#endif //CLIENT_TCPCLIENT_H
