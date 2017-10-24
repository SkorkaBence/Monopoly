#ifndef H_MONOPOLY_AI
#define H_MONOPOLY_AI

namespace Monopoly {

    class AI {
    protected:
        int moneyAtRoundStart = 0;
        int moneySpent = 0;
    public:
        void spendMoney(int mn);
        void clearSpendings(int money);
    };

}

#endif
