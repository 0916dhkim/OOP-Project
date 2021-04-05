/*
Final Project Milestone 1
Module    Time
Filename  Time.cpp
Version   1.0
Author    Donghyeon Kim
Revision History
--------------------------------------------------
Date        Reason
2021/03/14  Preliminary release.
--------------------------------------------------
I have done all the coding by myself and only
copied the code that my professor provided to
complete my workshops and assignments.
--------------------------------------------------*/
#include "Time.h"
#include "utils.h"
#include <iomanip>
using namespace std;
namespace sdds {
Time &Time::setToNow() {
  m_min = getTime();
  return *this;
}

Time::Time(unsigned int min) { m_min = min; };

ostream &Time::write(ostream &ostr) const {
  // Create a wrapper so this function does not affect
  // the original stream's flags.
  ostream timestream(ostr.rdbuf());

  // Dump.
  timestream << setfill('0') << setw(2);
  timestream << m_min / 60;
  timestream << ':';
  timestream << setfill('0') << setw(2);
  timestream << m_min % 60;

  return ostr;
}

istream &Time::read(istream &istr) {
  int firstNum = -1;
  int secondNum = -1;
  char c = 'c';

  istr >> firstNum;
  istr >> c;
  istr >> secondNum;

  if (firstNum >= 0 && secondNum >= 0 && c == ':' && istr) {
    // Valid input.
    m_min = firstNum * 60 + secondNum;
  } else {
    // Input failed.
    istr.clear(ios::failbit);
  }

  return istr;
}

Time &Time::operator-=(const Time &t) {
  m_min = ((m_min % 1440) + 1440 - (t.m_min % 1440)) % 1440;
  return *this;
}

Time Time::operator-(const Time &t) const {
  return Time(((m_min % 1440) + 1440 - (t.m_min % 1440)) % 1440);
}

Time &Time::operator+=(const Time &t) {
  m_min += t.m_min;
  return *this;
}

Time Time::operator+(const Time &t) const { return Time(m_min + t.m_min); }

Time &Time::operator=(unsigned int val) {
  m_min = val;
  return *this;
}

Time &Time::operator*=(unsigned int val) {
  m_min *= val;
  return *this;
}

Time &Time::operator/=(unsigned int val) {
  m_min /= val;
  return *this;
}

Time Time::operator*(unsigned int val) const { return Time(m_min * val); }

Time Time::operator/(unsigned int val) const { return Time(m_min / val); }

Time::operator unsigned int() const { return m_min; }

Time::operator int() const { return m_min; }

ostream &operator<<(ostream &ostr, const Time &t) {
  t.write(ostr);
  return ostr;
}

istream &operator>>(istream &istr, Time &t) {
  t.read(istr);
  return istr;
}
} // namespace sdds
