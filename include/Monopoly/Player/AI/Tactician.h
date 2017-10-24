#ifndef H_MONOPOLY_TACTICIAN
#define H_MONOPOLY_TACTICIAN

#include "Monopoly/Player/AI/AI.h"

namespace Monopoly {

    class Tactician : public AI {
    private:
        int purchasenum = 0;
    public:
        bool confirmPurchase(int price);
    };

}

#endif
