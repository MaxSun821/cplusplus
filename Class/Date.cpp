#include "Date.h"
// 构造函数
Date::Date(int year, int month, int day) {
    if(month > 0 && month < 13 && day > 0 && day <= GetDay(year, month)) {
        _year = year;
        _month = month;
        _day = day;
    }
    else {
        cout << "输入有误，日期赋初始值" << endl;
        _year = 1970;
        _month = 1;
        _day = 1;
    }
}
// 判断闰年
bool Date::IsLeapYear(int year) {
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
        return true;
    }
    return false;
}

// 获取该月的天数
int Date::GetDay(int year, int month) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(month == 2 && IsLeapYear(year)) {
        return 29;
    }
    return days[month];
}

// 打印函数
void Date::Print() {
    cout << _year << "/" << _month << "/" << _day << endl;
}

// 拷贝构造
Date::Date(const Date &d) {
    _year = d._year;
    _month = d._month;
    _day = d._day;
}

// d1 == d2
bool Date::operator==(const Date &d) {
    return _year == d._year
    && _month == d._month
    && _day == d._day;
}

// d1 != d2
bool Date::operator!=(const Date &d) {
    return !(*this == d);
}

// d1 < d2
bool Date::operator<(const Date &d) {
    if(_year < d._year) {
        return true;
    } else if(_year == d._year && _month < d._month) {
        return true;
    } else if(_year == d._year && _month == d._month && _day < d._day) {
        return true;
    } else {
        return false;
    }
}

// d1 <= d2
bool Date::operator<=(const Date &d) {
    return ((*this < d) || (*this == d));
}

// d1 > d2
bool Date::operator>(const Date &d) {
    return !(*this <= d);
}

//d1 >= d2
bool Date::operator>=(const Date &d) {
    return !(*this < d);
}

//赋值重载
Date& Date::operator=(const Date &d) {
    _year = d._year;
    _month = d._month;
    _day = d._day;

    return *this;
}

// d += 天数
Date& Date::operator+=(int day) {
    _day += day;
    while(_day > GetDay(_year, _month)) {
        _day -= GetDay(_year, _month);
        _month++;
        if(_month == 13) {
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
    while(_day < 1) {
        _month--;
        if(_month == 0) {
            _year--;
            _month = 12;
        }
        _day += GetDay(_year, _month);
    }
    return *this;
}

Date Date::operator-(int day) {
    Date tmp(*this);
    tmp -= day;
    return tmp;
}
