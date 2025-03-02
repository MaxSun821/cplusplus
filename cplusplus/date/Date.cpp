#include "Date.h"

Date::Date(int year, int month, int day) {
    if (year < 0 || month < 0 || day < 0) {
        cout << "Invalid date" << endl;
        return;
    }
    if (month > 12 || day > GetMonthDay(year, month)) {
        cout << "Invalid date" << endl;
        return;
    }
    year_ = year;
    month_ = month;
    day_ = day;
}

Date::Date(const Date &date) {
    year_ = date.year_;
    month_ = date.month_;
    day_ = date.day_;
}

Date& Date::operator=(const Date& date) {
    if (this != &date) {
        year_ = date.year_;
        month_ = date.month_;
        day_ = date.day_;
    }
    return *this;
}

bool Date::IsLeapYear(int year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        return true;
    }
    return false;
}


int Date::GetMonthDay(int year, int month) {
    static int month_day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && IsLeapYear(year)) {
        return 29;
    }
    return month_day[month];
}

Date::~Date() {
    year_ = 0;
    month_ = 0;
    day_ = 0;
}

bool Date::operator==(const Date& date) const {
    return year_ == date.year_ && month_ == date.month_ && day_ == date.day_;
}

bool Date::operator<(const Date& date) const {
    if (year_ < date.year_) {
        return true;
    }
    else if (year_ == date.year_ && month_ < date.month_) {
        return true;
    }
    else if (year_ == date.year_ && month_ == date.month_ && day_ < date.day_) {
        return true;
    }
    return false;
}

bool Date::operator>(const Date& date) const {
    return !(*this <= date);
}

bool Date::operator<=(const Date& date) const {
    return *this < date || *this == date;
}

bool Date::operator>=(const Date& date) const {
    return !(*this < date);
}

bool Date::operator!=(const Date& date) const {
    return !(*this == date);
}

Date& Date::operator+=(const int day) {
    if (day < 0) {
        *this -= day;
        return *this;
    }
    day_ += day;
    while (day_ > GetMonthDay(year_, month_)) {
        day_ -= GetMonthDay(year_, month_);
        month_++;
        if (month_ == 13) {
            month_ = 1;
            year_++;
        }
    }
    return *this;
}

Date& Date::operator-=(const int day) {
    if (day < 0) {
        *this += day;
        return *this;
    }
    day_ -= day;
    while (day_ < 0) {
        month_--;
        if (month_ == 0) {
            month_ = 12;
            year_--;
        }
        day_ += GetMonthDay(year_, month_);
    }
    return *this;
}

Date Date::operator+(const int day) const {
    Date tmp(*this);
    tmp += day;
    return tmp;
}

Date Date::operator-(const int day) const {
    Date tmp(*this);
    tmp -= day;
    return tmp;
}

Date& Date::operator++() {
    *this += 1;
    return *this;
}

Date Date::operator++(int) {
    Date tmp(*this);
    *this += 1;
    return tmp;
}

Date& Date::operator--() {
    *this -= 1;
    return *this;
}

Date Date::operator--(int) {
    Date tmp(*this);
    *this -= 1;
    return tmp;
}

int Date::operator-(const Date &date) {
    Date less = *this;
    Date more = date;
    if (*this > date) {
        more = *this;
        less = date;
    }
    int day = 0;
    while (less != more) {
        day++;
        less++;
    }
    return day;
}


ostream& operator<<(ostream& os, const Date& date) {
    os << date.year_ << "/" << date.month_ << "/" << date.day_;
    return os;
}
istream& operator>>(istream& is, Date& date) {
    is >> date.year_ >> date.month_ >> date.day_;
    return is;
}


