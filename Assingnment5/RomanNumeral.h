//
// Created by shivani goel on 2/24/18.
//

#ifndef ASSINGNMENT5_ROMANNUMERAL_H
#define ASSINGNMENT5_ROMANNUMERAL_H

#include <string>

using namespace std;

class RomanNumeral{
private:
    int decimal;
    string roman;
    void to_roman();
    void to_decimal();
    int get_value(char letter);


public:
    /*
     * Public Constructors
     */
    RomanNumeral();

    RomanNumeral(int decimal);

    RomanNumeral(const string &roman);
    /*
     * Public destructor
     */

    virtual ~RomanNumeral();

    /*
     * public getter and setter functions
     */

    int getDecimal() const;


    const string &getRoman() const;

    void setRoman(const string &roman);

    void setDecimal(int decimal);

    /*
     * Friend function : Operator overloading
     */
    friend bool operator ==(const RomanNumeral& rn1, const RomanNumeral& rn2);
    friend bool operator !=(const RomanNumeral& rn1, const RomanNumeral& rn2);
    friend int operator -(const RomanNumeral& rn1, const RomanNumeral& rn2);
    friend int operator +(const RomanNumeral& rn1, const RomanNumeral& rn2);
    friend int operator /(const RomanNumeral& rn1, const RomanNumeral& rn2);
    friend int operator *(const RomanNumeral& rn1, const RomanNumeral& rn2);

    /*
     * stream insertion operator overloading
     */
    friend ostream& operator<<(ostream& outs,const RomanNumeral& rn1);
    friend istream& operator>>(istream& ins,RomanNumeral& rn1)
    {
        string words;
        ins>>words;
        rn1.setRoman(words);
        return ins;
    }

};

#endif //ASSINGNMENT5_ROMANNUMERAL_H
