

#include "Date.h"


int Date::GetMonthDay(int year, int month)
{
    static int day[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if((year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && (month == 2)){
        return 29;
    }
    return day[month];
}

int Date::LeapYearDay(int year) {
    if((year % 4 == 0 && year % 100 != 0 || year % 400 == 0)){
        return 366;
    }
    return 365;
}

Date::Date(int year, int month, int day) {
    if(month > 0 && month < 13 && day > 0 && day <= Date::GetMonthDay(year, month)){
        _year = year;
        _month = month;
        _day = day;
    }else{
        cout << "日期不合法" << endl;
    }
}

void Date::Print(){
    cout << _year << "年" << _month << "月" << _day << "日" << endl;
}

bool Date::operator==(const Date& d){
    return _year == d._year
           && _month == d._month
           && _day == d._day;
}

bool Date::operator!=(const Date& d){
    return !(*this == d);
}

bool Date::operator<(const Date& d){
    if(_year < d._year){
        // 年小于就是小
        return true;
    }else if(_year == d._year && _month < d._month){
        // 年相等，月小于就是小
        return true;
    }else if(_month == d._month && _day < d._day){
        // 月等于，日小于就是小
        return true;
    }else{
        // 其余都是不小于
        return false;
    }
}

bool Date::operator<=(const Date& d){
    return *this < d || *this == d;
}

bool Date::operator>(const Date& d){
    return !(*this <= d);
}

bool Date::operator>=(const Date& d){
    return !(*this < d);
}

Date& Date::operator=(const Date& d){
    if(this != &d){
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }
    return *this;
}

Date& Date::operator+=(int day){
    if(day < 0) {
        *this -= -day;
        return *this;
    }
    _day += day;
    while(_day > Date::GetMonthDay(_year, _month)){
        _day -= Date::GetMonthDay(_year, _month);
        _month++;
        if(_month == 13){
            _year++;
            _month = 1;
        }
    }
    return *this;
}

Date Date::operator+(int day){
    Date tmp(*this);

    tmp += day;

    return tmp;
}

Date& Date::operator-=(int day){
    if(day < 0) {
        *this += -day;
        return *this;
    }
    _day -= day;
    while(_day <= 0){
        _month--;
        if(_month == 0){
            _year--;
            _month = 12;
        }
        _day += GetMonthDay(_year, _month);
    }
    return *this;
}

Date Date::operator-(int day){
    Date tmp(*this);

    tmp -= day;

    return tmp;
}

long Date::operator-(const Date& d){
    long day1 = 0L;
    long day2 = 0L;

    Date big(*this);
    Date small(d);

    if(big < small){
        big = d;
        small = *this;
    }

    for(int i = 1; i < big._month; i++){
        day1 += Date::GetMonthDay(big._year, i);
    }
    day1 += big._day;

    for(int i = 1; i < small._month; i++){
        day2 += Date::GetMonthDay(small._year, i);
    }
    day2 += small._day;

    for(int i = small._year; i < big._year; i++){
        day1 += Date::LeapYearDay(i);
    }

    return day1 - day2;


}

Date& Date::operator++(){
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

ostream& operator<<(ostream& out, const Date& d) {
    out << d._year << "年" << d._month << "月" << d._day << "日";
    return out;
}

istream& operator>>(istream& in, Date& d) {
    in >> d._year >> d._month >> d._day;
    return in;
}
