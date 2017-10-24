#ifndef H_MONOPOLY_EXCEPTION
#define H_MONOPOLY_EXCEPTION

#include <string>

namespace Monopoly {

    class MonopolyException {
    private:
        std::string message;
    public:
        MonopolyException(std::string msg);
        std::string getMessage();
    };

}

#endif
