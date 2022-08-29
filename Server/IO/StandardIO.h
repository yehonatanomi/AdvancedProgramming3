
#ifndef SERVER_STANDARDIO_H

#include "DefaultIO.h"

class StandardIO : public DefaultIO {
public:
    void send(std::string string) override;

    std::string read() override;
};


#endif

