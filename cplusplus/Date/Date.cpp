#include "Date.h"

void Date::print() {
	cout << _year << "/" << _month << "/" << _day << endl;
}

bool Date::operator<(Date d) {
	if (_year < d._year) {
		return true;
	}
	else if (_year == d._year && _month < d._month) {
		return true;
	}
	else if (_year == d._year && _month == d._month && _day < d._day) {
		return true;
	}
	return false;
}

bool Date::operator==(Date d) {
	return _year == d._year && _month == d._month && _day == d._day;
}
bool Date::operator<=(Date d) {
	return (*this) < d || (*this) == d;
}
bool Date::operator>(Date d) {
	return !((*this) <= d);
}
bool Date::operator>=(Date d) {
	return !((*this) < d);
}
bool Date::operator!=(Date d) {
	return !((*this) == d);
}

Date& Date::operator+=(int day) {
	_day += day;
	while (_day > getMonthDay(_year, _month)) {
		_day -= getMonthDay(_year, _month);
		_month++;
		if (_month > 12) {
			_year++;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator+(int day) {
	Date tmp(*this);
	tmp += day;
	return tmp;
}

Date& Date::operator-=(int day) {
	_day -= day;
	while (_day < 0) {
		_day += getMonthDay(_year, _month);
		_month--;
		if (_month == 0) {
			_year--;
			_month = 12;
		}
	}
	return *this;
}
Date Date::operator-(int day) {
	Date tmp(*this);
	tmp -= day;
	return tmp;
}
int Date::operator-(Date d) {
	int count = 0;
	Date less(*this);
	Date more(d);
	if (*this > d) {
		less = d;
		more = *this;
	}
	while (less != more) {
		count++;
		less += 1;
	}
	return count;
}

int Date::getMonthDay(int year, int month) {
	int monthArray[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
		return 29;
	}

	return monthArray[month];
}