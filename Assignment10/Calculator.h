//
// Created by shivani goel on 4/8/18.
//
#include<string>


using namespace std;

#ifndef ASSIGNMENT10_CALCULATOR_H
#define ASSIGNMENT10_CALCULATOR_H


class Calculator {

public:
    Calculator();

    double factor();
    double expression();
    double term();
    char token_read();
};


#endif //ASSIGNMENT10_CALCULATOR_H
