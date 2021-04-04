/*
Final Project Milestone 3
Module    Patient
Filename  Patient.h
Version   1.0
Author    Donghyeon Kim
Revision History
--------------------------------------------------
Date        Reason
2021/03/26  Preliminary release.
--------------------------------------------------
I have done all the coding by myself and only
copied the code that my professor provided to
complete my workshops and assignments.
--------------------------------------------------*/
#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H
#include "IOAble.h"
#include "Ticket.h"

namespace sdds {
class Patient : public IOAble {
private:
  char *m_name{nullptr};
  int m_ohip;
  Ticket m_ticket;
  bool m_isfile;

public:
  Patient(int ticketNumber = 0, bool isFile = false);
  Patient(const Patient &) = delete;
  Patient &operator=(const Patient &) = delete;
  ~Patient();
  virtual char type() const = 0;
  bool fileIO() const;
  void fileIO(bool value);
  bool operator==(char type) const;
  bool operator==(const Patient &) const;
  void setArrivalTime();
  operator Time() const;
  int number() const;
  std::ostream &csvWrite(std::ostream &ostr) const override;
  std::istream &csvRead(std::istream &istr) override;
  std::ostream &write(std::ostream &ostr) const override;
  std::istream &read(std::istream &istr) override;
};
} // namespace sdds

#endif
