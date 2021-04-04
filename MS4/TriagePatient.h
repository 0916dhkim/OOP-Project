/*
Final Project Milestone 4
Module    TriagePatient
Filename  TriagePatient.h
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
#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include "Patient.h"
namespace sdds {
class TriagePatient : public Patient {
private:
  char *mSymptoms{nullptr};

public:
  TriagePatient();
  ~TriagePatient();
  char type() const override;
  std::istream &csvRead(std::istream &) override;
  std::ostream &csvWrite(std::ostream &) const override;
  std::istream &read(std::istream &) override;
  std::ostream &write(std::ostream &) const override;
};
} // namespace sdds
#endif // !SDDS_TRIAGEPATIENT_H
