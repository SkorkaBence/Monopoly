#ifndef H_MONOPOLY_GREEDY
#define H_MONOPOLY_GREEDY

#include "Monopoly/Player/AI/AI.h"

namespace Monopoly {

    class Greedy : public AI {
    public:
        bool confirmPurchase(int price);
    };

}

#endif
