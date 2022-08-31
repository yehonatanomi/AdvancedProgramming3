#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include "TClient.h"
#include "../tools.h"
#include "thread"
#include <regex>

void handleMessage(const std::string &msg, TClient *client);

void receiving(TClient *client);

inline bool isFile(const std::string &name);

int main() {
    TClient client(inet_addr("127.0.0.1"), htons(55555));

    std::thread thread(receiving, &client);
    while (true) {
        std::string response;
        getline(std::cin, response);
        if (isFile(response)) {
            response = utils::readFile(response);
        }
        client.send(response);
    }
}

void receiving(TClient *client) {
    while (true) {
        const std::string &msg = client->recv();
        handleMessage(msg, client);
    }
}

void handleMessage(const std::string &msg, TClient *client) {
    if (msg == "exit") {
        client->close();
        exit(0);
    }
    //Check if a message should  print or saved to a file
    std::regex rgx("SAVE <((.|\\n)+)> TO <(.*)>");
    std::smatch matches;

    if (std::regex_search(msg, matches, rgx)) {
        utils::writeFile(matches[3].str(), matches[1].str());
    } else {
        std::cout << msg << std::endl;
    }
}

//Check if a string is a directory of a file
bool isFile(const std::string &name) {
    struct stat buffer{};
    return ((stat(name.c_str(), &buffer) == 0) and (buffer.st_mode & S_IFREG));
}
