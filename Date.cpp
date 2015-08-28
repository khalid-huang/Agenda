#include"Date.h"
#include<iostream>
#include<sstream>
using std::endl;
using std::cout;
Date::Date() {}
Date::Date(int y, int m, int d, int h, int mi) {
    year = y, month = m;
    day = d, hour = h;
    minute = mi;
}
int monthday(int a, int year) {
    int m_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day_;
    day_ = (a == 2 && (year % 400 == 0 ||(year % 4 == 0 && year % 100 != 0) ) ? 29 : m_day[a-1]);
    return day_;
}
Date Date::stringToDate(std::string time) {
    std::stringstream time_(time);
    Date date;
    char a;
    time_ >> date.year >> a >> date.month >> a >> date.day;
    time_ >> a >> date.hour >> a >> date.minute;
    if (isValid(date))
    return date;
    else
    cout << "The time is valid" << endl;
    return date;
}
std::string Date::dateToString(Date date) {
    std::stringstream out;
    std::string time_;
    if (!isValid(date)) {
    out << "The time is valid" << endl;
    time_ = out.str();
    return time_;
    }
    out << date.year << "-" << (date.month < 10 ? "0" : "");
    out << date.month << "-";
    out << (date.day < 10 ? "0":"") << date.day;
    out << "/" << (date.hour < 10 ? "0":"") << date.hour;
    out << ":" << (date.minute < 10 ? "0":"") << date.minute;
    time_ = out.str();
    return time_;
}
int Date::getYear()const {
  return year;
}
void Date::setYear(int year_) {
  year = year_;
}
void Date::setMonth(int month_) {
  month = month_;
}
void Date::setDay(int day_) {
  day = day_;
}
void Date::setHour(int hour_) {
  hour = hour_;
}
void Date::setMinute(int minute_) {
  minute = minute_;
}
int Date::getMonth()const {
  return month;
}
int Date::getDay()const {
  return day;
}
int Date::getHour()const {
  return hour;
}
int Date::getMinute()const {
  return minute;
}
bool Date::isValid(Date date) {
  if(date.year > 9999 || date.year < 1000 || (monthday(date.month, date.year) < date.day) || date.month > 12||date.minute >= 60 ||date.day <= 0 ||date.hour >= 24 )
    return false;
  return true;
}
Date& Date::operator=(const Date& date) {
  year = date.year;
  month = date.month;
  day = date.day;
  hour = date.hour;
  minute = date.minute;
  return *this;
}
bool Date::operator==(const Date& date) const {
  if (year == date.year && month == date.month && day == date.day && hour == date.hour && minute == date.minute)
    return true;
  return false;
}
bool Date::operator>(const Date& date)const {
if (year > date.year)
    return true;
    if (year ==  date.year && month > date.month)
    return true;
    if (year ==  date.year && month == date.month && day > date.day)
    return true;
    if (year ==  date.year && month == date.month && day == date.day && hour > date.hour)
    return true;
    if (year ==  date.year && month == date.month && day == date.day && hour == date.hour
    && minute > date.minute)
    return true;
    return false;
}
bool Date::operator<(const Date& date)const {
  if (*this == date || *this > date)
    return false;
  return true;
}
bool Date::operator>=(const Date& date)const {
  if (*this == date || *this > date)
    return true;
  return false;
}
bool Date::operator<=(const Date& date)const {
  if (*this == date || *this < date)
    return true;
  return false;
}
