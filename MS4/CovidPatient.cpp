/*
Final Project Milestone 4
Module    CovidPatient
Filename  CovidPatient.cpp
Version   1.0
Author    Donghyeon Kim
Revision History
--------------------------------------------------
Date        Reason
2021/04/03  Preliminary release.
--------------------------------------------------
I have done all the coding by myself and only
copied the code that my professor provided to
complete my workshops and assignments.
--------------------------------------------------*/
#include "CovidPatient.h"
using namespace std;
namespace sdds {
int nextCovidTicket = 1;

CovidPatient::CovidPatient() : Patient(nextCovidTicket++) {}
char CovidPatient::type() const { return 'C'; }
istream &CovidPatient::csvRead(istream &istr) {
  Patient::csvRead(istr);
  nextCovidTicket = number() + 1;
  istr.ignore(1000, '\n');

  return istr;
}
ostream &CovidPatient::write(ostream &ostr) const {
  if (fileIO()) {
    csvWrite(ostr);
  } else {
    ostr << "COVID TEST" << endl;
    Patient::write(ostr) << endl;
  }
  return ostr;
}
istream &CovidPatient::read(istream &istr) {
  if (fileIO()) {
    csvRead(istr);
  } else {
    Patient::read(istr);
  }
  return istr;
}
} // namespace sdds