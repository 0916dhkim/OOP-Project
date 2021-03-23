/*
Final Project Milestone 1
Module    IOAble
Filename  IOAble.h
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
#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H
#include <iostream>

namespace sdds {
class IOAble {
public:
  virtual ~IOAble(){};

  virtual std::ostream &csvWrite(std::ostream &) const = 0;
  virtual std::istream &csvRead(std::istream &) = 0;
  virtual std::ostream &write(std::ostream &) const = 0;
  virtual std::istream &read(std::istream &) = 0;
};
} // namespace sdds

std::ostream &operator<<(std::ostream &, sdds::IOAble &);
std::istream &operator>>(std::istream &, sdds::IOAble &);

#endif
