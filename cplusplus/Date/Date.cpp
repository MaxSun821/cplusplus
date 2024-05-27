#include "Date.h"


Date::Date(int year, int month, int day) {
    _year = year;
    _month = month;
    _day = day;

    if (month < 1 || month > 12
        || day < 1 || day > getMonthDay(year, month)) {
        cout << "日期格式错误" << endl;
    }
}

void Date::print() const {
    cout << _year << "/" << _month << "/" << _day << endl;
}

bool Date::operator<(Date d) const {
    if (_year < d._year) {
        return true;
    } else if (_year == d._year && _month < d._month) {
        return true;
    } else if (_year == d._year && _month == d._month && _day < d._day) {
        return true;
    }
    return false;
}

bool Date::operator==(Date d) const {
    return _year == d._year && _month == d._month && _day == d._day;
}

bool Date::operator<=(Date d) const {
    return (*this) < d || (*this) == d;
}

bool Date::operator>(Date d) const {
    return !((*this) <= d);
}

bool Date::operator>=(Date d) const {
    return !((*this) < d);
}

bool Date::operator!=(Date d) const {
    return !((*this) == d);
}


Date &Date::operator=(const Date &d) {
    _year = d._year;
    _month = d._month;
    _day = d._day;

    return *this;
}

Date &Date::operator+=(int day) {
    if (day < 0) {
        return *this -= (-day);
    }
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

Date Date::operator+(int day) const {
    Date tmp(*this);
    tmp += day;
    return tmp;
}

Date &Date::operator-=(int day) {
    if (day < 0) {
        return *this += (-day);
    }
    _day -= day;
    while (_day <= 0) {

        _month--;
        if (_month == 0) {
            _year--;
            _month = 12;
        }
        _day += getMonthDay(_year, _month);
    }
    return *this;
}

Date Date::operator-(int day) const {
    Date tmp(*this);
    tmp -= day;
    return tmp;
}

int Date::operator-(const Date &d) const {
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

Date &Date::operator++() {
    return *this += 1;
}

Date Date::operator++(int) {
    Date tmp = *this;
    *this += 1;
    return tmp;
}

Date &Date::operator--() {
    return *this -= 1;
}

Date Date::operator--(int) {
    Date tmp = *this;
    *this -= 1;
    return tmp;
}

int Date::getMonthDay(int year, int month) {
    int monthArray[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
        return 29;
    }

    return monthArray[month];
}

ostream &operator<<(ostream &out, const Date &d) {
    out << d._year << "/" << d._month << "/" << d._day;
    return out;
}

istream &operator>>(istream &in, Date &d) {
    in >> d._year >> d._month >> d._day;
    return in;
}