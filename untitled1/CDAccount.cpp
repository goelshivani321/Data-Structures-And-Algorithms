//
// Created by shivani goel on 2/27/18.
//

#include "CDAccount.h"

CDAccount::CDAccount(double bal,double rate,int terms):balance(bal),interest_rate(rate),term(terms) {}
//Default Constructor
CDAccount::CDAccount() {}

double CDAccount::get_balance()
{
    return balance;
}

double CDAccount::get_interest_rate()
{
    return interest_rate;
}

int CDAccount::get_term()
{
    return term;
}

double CDAccount::balance_at_maturity()
{
    return (balance*term*interest_rate/100);
}

CDAccount::~CDAccount() {

}


