//
// Created by yehonatan on 8/29/2022.
//
#include <netinet/in.h>
#include "string"

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H


class Tserver {
    private:
        int sockId;
        int queueLen = 5;
        int clientNum = 0;
        struct sockaddr_in from;
        fd_set readfds;
        struct timeval tv;
    public:
        Tserver(in_addr_t ip, in_port_t port);

        int accept();

        void close() const;

        ~Tserver() = default;

        void disconnectClient();

        int getClientNum() const;

};


#endif //SERVER_SERVER_H
