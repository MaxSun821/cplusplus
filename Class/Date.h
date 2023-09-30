

#ifndef CLASS_DATE_H
#define CLASS_DATE_H

#include <iostream>
using namespace std;


class Date {
    friend ostream& operator<<(ostream& out, const Date& d);
    friend istream& operator>>(istream& in, Date& d);
private:
    int _year;
    int _month;
    int _day;
public:
    Date(int year = 1970, int month = 1, int day = 1);

    int GetMonthDay(int year, int month);
    int LeapYearDay(int year);

    bool operator==(const Date& d);
    bool operator!=(const Date& d);
    bool operator<(const Date& d);
    bool operator<=(const Date& d);
    bool operator>(const Date& d);
    bool operator>=(const Date& d);

    Date& operator=(const Date& d);

    Date& operator+=(int day);
    Date operator+(int day);

    Date& operator-=(int day);
    Date operator-(int day);
    long operator-(const Date& d);

    Date& operator++();
    Date operator++(int);

    Date& operator--();
    Date operator--(int);

    void Print();
};

ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);


#endif //CLASS_DATE_H
