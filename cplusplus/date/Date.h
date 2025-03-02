#ifndef DATE_H
#define DATE_H

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::istream;

class Date {
    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&);
private:
    bool IsLeapYear(int year);
public:
    int GetMonthDay(int year, int month);
    Date(int year = 1970, int month = 1, int day = 1);
    Date(const Date& date);
    Date& operator=(const Date& date);
    ~Date();
    bool operator==(const Date& date) const;
    bool operator<(const Date& date) const;
    bool operator>(const Date& date) const;
    bool operator<=(const Date& date) const;
    bool operator>=(const Date& date) const;
    bool operator!=(const Date& date) const;

    // 日期+=天数
    Date& operator+=(const int day);
    // 日期-=天数
    Date& operator-=(const int day);
    // 日期+天数
    Date operator+(const int day) const;
    // 日期-天数
    Date operator-(const int day) const;
    // 日期-日期
    int operator-(const Date& date);
    // 日期++后置++
    Date& operator++();
    // 后置--
    Date& operator--();
    // 日期++前置++
    Date operator++(int);
    // 前置--
    Date operator--(int);

private:
    int year_;
    int month_;
    int day_;
};

ostream& operator<<(ostream& os, const Date& date);
istream& operator>>(istream& is, Date& date);

#endif //DATE_H
