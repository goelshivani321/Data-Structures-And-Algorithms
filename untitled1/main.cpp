#include <iostream>
#include <stdio.h>
#include <string>
#include "CDAccount.h"
using namespace std;

#include <stdio.h>

struct Date
{
    int month;
    string day;
    int year;

};

int main()
{
    double balance, int_rate;
    int term;

    cout<<"Enter Balance Int rate term\n";
    cin>>balance>>int_rate>>term;

    CDAccount account,account2(balance,int_rate,term);
    cout<<account2.balance_at_maturity()<<endl;

   cout<<account.get_balance();


    return 0;

}