//
// Created by yehonatan on 8/29/2022.
//

#ifndef SERVER_UTILS_H
#define SERVER_UTILS_H


#include "vector"
#include "string"

namespace utils {
    std::string readFile(const std::string &);

    std::vector<std::vector<std::string>> readCSV(const std::string &);

    void writeFile(const std::string &path, const std::string &content);

    std::vector<std::string> split(const std::string &, char);

    std::string recv(int);

    void send(int, const std::string &);
}

#endif //SERVER_UTILS_H
