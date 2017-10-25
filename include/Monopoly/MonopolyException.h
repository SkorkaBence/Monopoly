#ifndef H_MONOPOLY_EXCEPTION
#define H_MONOPOLY_EXCEPTION

#include <string>
#include <exception>

namespace Monopoly {

    class MonopolyException : public std::exception {
    private:
        std::string message;
    public:
        MonopolyException(std::string msg);
        std::string getMessage();
        const char * what () const throw () {
            return "MonopolyException";
        }
    };

}

#endif
