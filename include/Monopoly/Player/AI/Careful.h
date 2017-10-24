#ifndef H_MONOPOLY_CAREFUL
#define H_MONOPOLY_CAREFUL

#include "Monopoly/Player/AI/AI.h"

namespace Monopoly {

    class Careful : public AI {
    public:
        bool confirmPurchase(int price);
    };

}

#endif
