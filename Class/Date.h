

#ifndef CLASS_DATE_H
#define CLASS_DATE_H

#include <iostream>
using namespace std;

class Date {

public:
    friend ostream& operator<<(ostream& out, const Date& d);
    Date(int year = 1970, int month = 1, int day = 1);
    bool IsLeapYear(int year);
    int GetDay(int year, int month);
    void Print();
    Date(const Date& d);

    // 运算符重载
    bool operator==(const Date& d);
    bool operator!=(const Date& d);
    bool operator<(const Date& d);
    bool operator<=(const Date& d);
    bool operator>(const Date& d);
    bool operator>=(const Date& d);

    Date& operator+=(int day);
    Date operator+(int day);

    Date& operator-=(int day);
    Date operator-(int day);
    int operator-(const Date& d);

    Date& operator++();
    Date operator++(int);

    Date& operator--();
    Date operator--(int);

    // 赋值重载
    Date& operator=(const Date& d);
private:
    int _year;
    int _month;
    int _day;
};

ostream& operator<<(ostream& out, const Date& d);


#endif //CLASS_DATE_H
