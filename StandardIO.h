
#ifndef SERVER_STANDARDIO_H
#define SERVER_STANDARDIO_H

#include "DefaultIO.h"

class StandardIO : public DefaultIO {
public:
    void write(std::string string) override;

    std::string read() override;
};


#endif //CLIENT_STANDARDIO_H

