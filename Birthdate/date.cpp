//
// Created by shivani goel on 3/14/18.
//
#include<iostream>
#include "date.h"

using namespace std;

date::date() {
    day=0;
    month=0;
    year=2000;
}

date::date(int day,int month,int year): day(day),month(month),year(year){

}

void date::setDay(int day) {
    date::day = day;
}

void date::setMonth(int month) {
    date::month= month;
}

void date::setYear(int year){
    date::year=year;
}

int date::get_day() const{
    return day;
}

int date::get_month() const{
    return month;
}

int date::get_year() const{
    return year;
}

bool equal(const date& date1,const date& date2)
{
    return (date1.get_day()==date2.get_day());
}

int operator +(const date& d1,const date& d2)
{
    return abs(d1.year+d2.year);
}

int operator -(const date& d1,const date& d2)
{
    return abs(d1.year-d2.year);
}

date::~date() {
    cout<<"Destructor";
}
