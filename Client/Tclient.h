//
// Created by yehonatan on 8/29/2022.
//

#ifndef SERVER_CLIENT_H
#define SERVER_CLIENT_H


#include <netinet/in.h>
#include "string"

class Tclient {
private:
    int sock;
    struct sockaddr_in sin;
public:
    void send(const std::string &string) const;

    std::string recv() const;

    void close() const;

    Tclient(in_addr_t, in_port_t);

    ~Tclient() = default;
};

#endif //SERVER_CLIENT_H
