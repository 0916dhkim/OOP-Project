/*
Final Project Milestone 1
Module    PreTriage
Filename  PreTriage.h
Version   1.0
Author    Donghyeon Kim
Revision History
--------------------------------------------------
Date        Reason
2021/04/05  Preliminary release.
--------------------------------------------------
I have done all the coding by myself and only
copied the code that my professor provided to
complete my workshops and assignments.
--------------------------------------------------*/
#ifndef SDDS_PRETRIAGE_H
#define SDDS_PRETRIAGE_H
#include "Menu.h"
#include "Patient.h"
#include "Time.h"
#include <iostream>
namespace sdds {
const int maxNoOfPatients = 100;
class PreTriage {
  Time m_averCovidWait, m_averTriageWait;
  Patient *m_lineup[maxNoOfPatients]{};
  char *m_dataFilename{nullptr};
  int m_lineupSize{0};
  Menu m_appMenu, m_pMenu;
  void reg();
  void admit();
  const Time getWaitTime(const Patient &p) const;
  void setAverageWaitTime(const Patient &p);
  void removePatientFromLineup(int index);
  int indexOfFirstInLine(char type) const;
  void load();

  // Dump data.
  std::ostream &write(std::ostream &, bool fileIO) const;

public:
  PreTriage(const char *dataFilename);
  ~PreTriage();
  void run(void);
};
} // namespace sdds
#endif
