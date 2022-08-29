#include "DefaultIO.h"
#include "string"

#ifndef TESTING_SOCKETIO_H
#define TESTING_SOCKETIO_H


class SocketIO : public DefaultIO {
private:
    int socket;
public:
    explicit SocketIO(int socket);

    void send(std::string) override;

    std::string read() override;

    ~SocketIO();

};


#endif