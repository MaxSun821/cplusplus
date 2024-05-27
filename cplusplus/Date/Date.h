#pragma once

#include <iostream>
#include <cstdbool>

using namespace std;

class Date {
    friend ostream &operator<<(ostream &out, const Date &d);

    friend istream &operator>>(istream &in, Date &d);

public:
    Date(int year = 1970, int month = 1, int day = 1);

    int getMonthDay(int year, int month);

    bool operator<(Date d) const;

    bool operator==(Date d) const;

    bool operator<=(Date d) const;

    bool operator>(Date d) const;

    bool operator>=(Date d) const;

    bool operator!=(Date d) const;

    Date &operator=(const Date &d);

    Date &operator+=(int day);

    Date operator+(int day) const;

    Date &operator-=(int day);

    Date operator-(int day) const;

    int operator-(const Date &d) const;

    Date &operator++();

    Date operator++(int);

    Date &operator--();

    Date operator--(int);

    void print() const;

private:
    int _year;
    int _month;
    int _day;
};

ostream &operator<<(ostream &out, const Date &d);

istream &operator>>(istream &in, Date &d);