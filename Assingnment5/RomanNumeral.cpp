//
// Created by shivani goel on 2/24/18.
//
#include <iostream>
#include<cmath>
#include "RomanNumeral.h"

using namespace std;
/*
 * Defining constructors
 */
RomanNumeral::RomanNumeral(int decimal)
{
    RomanNumeral::setDecimal(decimal);

}

RomanNumeral::RomanNumeral(const string &roman)
{
    RomanNumeral::setRoman(roman);
}

RomanNumeral::RomanNumeral() {
    roman="";
    decimal=0;
}
/*
 * Defining destructor
 */

RomanNumeral::~RomanNumeral() {

}
/*
 * Defining getter and setter for roman and decimal
 */

int RomanNumeral::getDecimal() const {
    return decimal;
}

const string &RomanNumeral::getRoman() const {
    return roman;
}

void RomanNumeral::setRoman(const string &roman) {
    RomanNumeral::roman = roman;
    to_decimal();
}

void RomanNumeral::setDecimal(int decimal) {
    RomanNumeral::decimal = decimal;
    to_roman();
}

/*
 * operator overloading
 */

bool operator ==(const RomanNumeral& rn1,const RomanNumeral& rn2)
{
    return (rn1.getDecimal()==rn2.getDecimal()|| rn1.getRoman()==rn2.getRoman());
}

bool operator !=(const RomanNumeral& rn1,const RomanNumeral& rn2)
{
    return (rn1.getDecimal()!=rn2.getDecimal()|| rn1.getRoman()!=rn2.getRoman());
}

int operator -(const RomanNumeral& rn1,const RomanNumeral& rn2)
{
    return abs(rn1.getDecimal()-rn2.getDecimal());
}
int operator +(const RomanNumeral& rn1,const RomanNumeral& rn2)
{
    return abs(rn1.getDecimal()+rn2.getDecimal());
}

int operator *(const RomanNumeral& rn1,const RomanNumeral& rn2)
{
    return abs(rn1.getDecimal()*rn2.getDecimal());
}

int operator /(const RomanNumeral& rn1,const RomanNumeral& rn2)
{
    return abs(rn1.getDecimal()/rn2.getDecimal());
}

ostream& operator <<(ostream& outs,const RomanNumeral& rn1)
{

    outs<<"["<<rn1.decimal<<":"<<rn1.roman<<"]";
    return outs;
}



int RomanNumeral:: get_value(char letter)
{
    if (letter == 'I') return 1;
    if (letter == 'V') return 5;
    if (letter == 'X') return 10;
    if (letter == 'L') return 50;
    if (letter == 'C') return 100;
    if (letter == 'D') return 500;
    if (letter == 'M') return 1000;
    return -1;
}
/*
 * function to convert roman numeral to decimal
 */
void RomanNumeral::to_decimal()
{
    int sum = 0;
    int length=roman.length();

    for(int i=0;i<length;i++)
    {
        int val = get_value(roman[i]);
        if (i+1 < length)
        {
            int digit2 = get_value(roman[i+1]);

            if (val >= digit2)
            {
                sum = sum + val;
            }
            else
            {
                sum = sum + digit2 - val;
                i++;
            }
        }
        else
        {
            sum = sum + val;
            i++;
        }
    }
    decimal=sum;
}
/*
 * definition for to_roman: converts decimal to roman
 */

void RomanNumeral::to_roman()
{
    string result;
    int val=decimal;
    struct keyVal
    {
        int val;
        char const* roman_key;

    };

    static keyVal const keyVal_pair[]=
            { 1000, "M", 900, "CM", 500, "D",400, "CD", 100, "C", 90, "XC", 50, "L", 40, "XL", 10, "X", 9, "IX", 5, "V",
              4, "IV",
              1, "I",
              0, NULL };

    for (keyVal const* counter = keyVal_pair; counter->val > 0; ++counter)
    {
        while (val >= counter->val)
        {
            result += counter->roman_key;
            val  -= counter->val;
        }
    }
    roman=result;
}


