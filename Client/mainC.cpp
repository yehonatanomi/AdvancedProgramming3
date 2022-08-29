//
// Created by yehonatan on 8/29/2022.
//
#include "Tclient.h"
#include "../tools.h"
#include <thread>
#include <regex>
#include <iostream>
#include <arpa/inet.h>

void handleMessage(const std::string &msg, Tclient *client, int i);

void receiving(Tclient *client);


int main() {
    Tclient client(inet_addr("127.0.0.1"), 5555);

    std::thread thread(receiving, &client);

   ////עדיין לא החזיר דבר
}

void receiving(Tclient *client) {
    int i =0;
    while (true) {
        const std::string &msg = client->recv();
        handleMessage(msg, client,i);
        i++;
    }
}

void handleMessage(const std::string &msg, Tclient *client, int i) {
    if (msg == "exit") {
        client->close();
        exit(0);
    }
   /////// פה עושים דברים
   std::cout<<msg <<" "<< i<< std::endl;
}

