#ifndef H_MONOPOLY_AI
#define H_MONOPOLY_AI

namespace Monopoly {

    class Player;

    class AI {
    protected:
        int moneyAtRoundStart = 0;
        int moneySpent = 0;
        int actualMoney = 0;

        Player* player;
    public:
        void spendMoney(int mn);
        void clearSpendings(int money);
        void init(Player* owner);
        virtual bool confirmPurchase(int price) = 0;
    };

}

#endif
