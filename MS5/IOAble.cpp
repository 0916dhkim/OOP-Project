/*
Final Project Milestone 1
Module    IOAble
Filename  IOAble.cpp
Version   1.0
Author    Donghyeon Kim
Revision History
--------------------------------------------------
Date        Reason
2021/03/22  Preliminary release.
--------------------------------------------------
I have done all the coding by myself and only
copied the code that my professor provided to
complete my workshops and assignments.
--------------------------------------------------*/
#include "IOAble.h"

std::ostream &operator<<(std::ostream &ostr, sdds::IOAble &i) {
  return i.write(ostr);
}
std::istream &operator>>(std::istream &istr, sdds::IOAble &i) {
  return i.read(istr);
}