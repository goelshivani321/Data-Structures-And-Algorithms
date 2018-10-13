//
// Created by shivani goel on 3/14/18.
//

#ifndef BIRTHDATE_DATE_H
#define BIRTHDATE_DATE_H
#include <ostream>

class date {
private:
    int day,year,month;

public:
    date();
    date(int day,int month,int year);

    int get_year() const;
    int get_day() const;
    int get_month() const;

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    bool equal(const date& date1,const date& date2);
    friend int operator -(const date& d1,const date& d2);
    friend int operator +(const date& d1, const date& d2);
    friend ostream& operator <<(ostream& outs,const date& d1);
    friend istream&operator >>(istream& ins,date& d1);


    ~date();


};


#endif //BIRTHDATE_DATE_H
