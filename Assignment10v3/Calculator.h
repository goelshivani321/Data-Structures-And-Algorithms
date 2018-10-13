//
// Created by shivani goel on 4/10/18.
//

#ifndef ASSIGNMENT10V3_CALCULATOR_H
#define ASSIGNMENT10V3_CALCULATOR_H


class Calculator {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value
    Calculator(char kind, double value);
    Calculator(char kind);

    double term();
    double expression();
    double factor();



};


#endif //ASSIGNMENT10V3_CALCULATOR_H
