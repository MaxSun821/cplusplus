#pragma once

#include <iostream>
#include <cstdbool>
using namespace std;

class Date {
public:
	Date(int year = 1970, int month = 1, int day = 1) {
		_year = year;
		_month = month;
		_day = day;
	}
	int getMonthDay(int year, int month);
	bool operator<(Date d);
	bool operator==(Date d);
	bool operator<=(Date d);
	bool operator>(Date d);
	bool operator>=(Date d);
	bool operator!=(Date d);

	Date& operator+=(int day);
	Date operator+(int day);
	Date& operator-=(int day);
	Date operator-(int day);
	int operator-(Date d);
	void print();
private:
	int _year;
	int _month;
	int _day;
};