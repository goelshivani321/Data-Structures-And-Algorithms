//
// Created by shivani goel on 4/8/18.
//

#include "Calculator.h"
#include <iostream>
#include <cmath>
using namespace std;


Calculator::Calculator() {}
/*
 * Reads each character
 */

char Calculator::token_read()
{
    char ch;
    cin >> ch;
    return ch;
}

double Calculator::factor() {
    double val = 0;
    //char ch = token_read();
    char ch = cin.peek();
     if (ch == '(')
    {
        char ch = token_read();
        val = expression();
        ch = token_read();
        //ch = cin.peek();
        if (ch != ')')
        {
            string error = std::string("***** Missing )");
            if(ch=='=') cin.unget();
            throw runtime_error(error.c_str());
        }
    }
    else if (isdigit(ch))
    {
        cin >> val;
    }

    else if(ch=='-')
     {
         cin>>ch;
         return -factor();
     }
     else if(ch=='+')
     {
         cin>>ch;
         return factor();
     }

    else throw runtime_error("Unexpected character");
    return val;

}

double Calculator::expression() {
    double val = term();

   char ch=cin.peek();
    //handling + and -
    if (ch == '-' || ch=='+')
    {
        char ch = token_read();
        //calling expression again
        double ex = expression();
        if (ch == '+')
            val += ex;
        else
            val -= ex;
    }
    return val;
}

double Calculator::term() {

    double ch;
    double val = power();
    //ch = token_read();
    ch = cin.peek();
    if (ch == '*' || ch == '/')
    {
        ch = token_read();
        double f = term();

        if (ch == '*')
            val *= f;
        else
        {
            //error handling for divide by 0
            if(f==0)
            {
                throw runtime_error("***** Division by zero");
            }
            else
            {
                val /= f;
                if(val == 0)
                {
                    throw runtime_error("***** Division by zero");
                }
            }
        }
    }

    return val;

}

double Calculator::power()
{
    double ch;
    double val=factor();
    ch=cin.peek();

    if(ch=='^')
    {
        ch=token_read();
        double p=power();
        val=pow(val,p);
    }
    return val;
}

