#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
 public:
  Date();
  Date(int y, int m, int d, int h, int mi);
  int getYear() const;
  void setYear(int year);
  int getMonth() const;
  void setMonth(int month);
  int getDay() const;
  void setDay(int day);
  int getHour() const;
  void setHour(int hour);
  int getMinute(void) const;
  void setMinute(int minute);
  static bool isValid(Date date);
  static Date stringToDate(std::string dateString);
  static std::string dateToString(Date date);
  Date &operator=(const Date& date);
  bool operator==(const Date& date) const;
  bool operator>(const Date& date) const;
  bool operator<(const Date& date) const;
  bool operator>=(const Date& date) const;
  bool operator<=(const Date& date) const;

 private:
  int year;
  int month;
  int day;
  int hour;
  int minute;
};
#endif
