//
// Created by shivani goel on 2/27/18.
//

#ifndef UNTITLED1_CDACCOUNT_H
#define UNTITLED1_CDACCOUNT_H


class CDAccount {
private:
    double balance;
    double interest_rate;
    int term;

public:
    CDAccount();
    CDAccount(double balance,double interest_rate,int term);

    double get_balance();
    double get_interest_rate();
    int get_term();

    double balance_at_maturity();

    virtual ~CDAccount();

};


#endif //UNTITLED1_CDACCOUNT_H
