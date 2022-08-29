
#include "string"
#ifndef CLIENT_DEFAULTIO_H
#define CLIENT_DEFAULTIO_H


class DefaultIO {
public:
    virtual std::string read() = 0;

    virtual void send(std::string string) = 0;
};


#endif //CLIENT_DEFAULTIO_H
#endif SERVER_DEFAULTIO_H
