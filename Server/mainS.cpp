//
// Created by yehonatan on 8/29/2022.
//
#include <iostream>
#include "../tools.h"
#include "Tserver.h"
#include "thread"

void handleNewClient(int clientSock, Tserver *server);

int main() {
    std::cout<<1;
    const int server_port = 5555;
    Tserver server(AF_INET, 5555);
    while (true) {
        int clientSock = server.accept();

        if (clientSock == -1) {
            break;
        }
        std::thread handlingClient(handleNewClient,clientSock, &server);
        handlingClient.detach();
    }
    server.close();
}

void handleNewClient(int clientSock, Tserver *server) {
    std::string s ="h";
    while (s!= "exit") {
        std::cin >> s;
    }
    server->disconnectClient();
}