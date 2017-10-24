#include "Monopoly/MonopolyException.h"

namespace Monopoly {

    MonopolyException::MonopolyException(std::string msg) message(msg) {
    }

    std::string MonopolyException::getMessage() {
        return msg;
    }

}
