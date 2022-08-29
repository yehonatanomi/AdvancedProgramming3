#include "StandardIO.h"
#include "iostream"

std::string StandardIO::read() {
    std::string res;
    getline(std::cin, res);
    return res;
}

void StandardIO::send(std::string string) {
    std::cout << string << std::endl;
}