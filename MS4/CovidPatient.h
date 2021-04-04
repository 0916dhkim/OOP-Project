/*
Final Project Milestone 4
Module    CovidPatient
Filename  CovidPatient.h
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
#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include "Patient.h"

namespace sdds {
class CovidPatient : public Patient {
public:
  CovidPatient();
  char type() const override;
  std::istream &read(std::istream &istr) override;
  std::ostream &write(std::ostream &ostr) const override;
  std::istream &csvRead(std::istream &istr) override;
};
} // namespace sdds
#endif // !SDDS_COVIDPATIENT_H_
