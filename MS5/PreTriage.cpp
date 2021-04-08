/*
Final Project Milestone 1
Module    PreTriage
Filename  PreTriage.cpp
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
#include "PreTriage.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "utils.h"
#include <cstring>
#include <fstream>

using namespace std;
namespace sdds {
PreTriage::PreTriage(const char *dataFilename)
    : m_averCovidWait(15), m_averTriageWait(5),
      m_appMenu(
          "General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
      m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) {
  if (dataFilename != nullptr) {

    m_dataFilename = new char[strlen(dataFilename) + 1];
    strcpy(m_dataFilename, dataFilename);
  }
  load();
}
ostream &PreTriage::write(ostream &ostr, bool fileIO) const {
  // Average wait time.
  if (fileIO) {
    ostr << m_averCovidWait << ',' << m_averTriageWait << endl;
  } else {
    ostr << "Saving Average Wait Time," << endl;
    ostr << "   COVID Test: " << m_averCovidWait << endl;
    ostr << "   Triage: " << m_averTriageWait << endl;
  }

  // Patient info.
  for (int i = 0; i < m_lineupSize; i++) {
    if (!fileIO) {
      ostr << (i + 1) << "- ";
    }
    m_lineup[i]->csvWrite(ostr) << endl;
  }

  return ostr;
}
PreTriage::~PreTriage() {
  ofstream fileStream(m_dataFilename);
  write(fileStream, true);
  write(cout, false);
  fileStream.close();

  for (int i = 0; i < m_lineupSize; i++) {
    delete m_lineup[i];
  }
  delete[] m_dataFilename;

  cout << "done!" << endl;
}
const Time PreTriage::getWaitTime(const Patient &p) const {
  Time averageWait = p.type() == 'C' ? m_averCovidWait : m_averTriageWait;
  unsigned count = 0;
  for (int i = 0; i < m_lineupSize; i++) {
    if (*m_lineup[i] == p) {
      count++;
    }
  }

  return averageWait * count;
}
void PreTriage::setAverageWaitTime(const Patient &p) {
  Time currentTime, patientTicketTime(p);
  Time *target = p.type() == 'C' ? &m_averCovidWait : &m_averTriageWait;

  *target = ((currentTime - patientTicketTime) +
             (*target * (unsigned)(p.number() - 1))) /
            (unsigned)p.number();
}
void PreTriage::removePatientFromLineup(int index) {
  removeDynamicElement(m_lineup, index, m_lineupSize);
}
int PreTriage::indexOfFirstInLine(char type) const {
  for (int i = 0; i < m_lineupSize; i++) {
    if (*m_lineup[i] == type) {
      return i;
    }
  }
  return -1;
}
void PreTriage::load() {
  cout << "Loading data..." << endl;
  ifstream fileStream(m_dataFilename);

  // Load wait times.
  fileStream >> m_averCovidWait;
  fileStream.ignore(1000, ',');
  fileStream >> m_averTriageWait;
  fileStream.ignore(1000, '\n');

  // Load patient info.
  for (int i = 0; i < maxNoOfPatients && fileStream.good(); i++) {
    Patient *pPatient = nullptr;
    char type = 0;
    fileStream >> type;
    fileStream.ignore(1000, ',');
    if (type == 'C') {
      pPatient = new CovidPatient();
    } else if (type == 'T') {
      pPatient = new TriagePatient();
    }

    if (pPatient != nullptr) {
      pPatient->fileIO(true);
      pPatient->read(fileStream);
      pPatient->fileIO(false);
      m_lineup[i] = pPatient;
      m_lineupSize = i + 1;
    }
  }

  // Wrap up.
  if (m_lineupSize == maxNoOfPatients && fileStream.peek() != EOF) {
    cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
  }

  if (m_lineupSize == 0) {
    cout << "No data or bad data file!" << endl;
  } else {
    cout << m_lineupSize << " Records imported..." << endl;
  }
}
void PreTriage::reg() {
  if (m_lineupSize == maxNoOfPatients) {
    cout << "Line up full!" << endl;
    return;
  }

  int menuSelection = -1;
  m_pMenu >> menuSelection;

  Patient *nextPatient = nullptr;

  switch (menuSelection) {
  case 1:
    nextPatient = new CovidPatient();
    break;
  case 2:
    nextPatient = new TriagePatient();
    break;
  case 0:
    return;
  }

  nextPatient->setArrivalTime();

  cout << "Please enter patient information: " << endl;
  nextPatient->fileIO(false);
  nextPatient->read(cin);
  cout << endl << "******************************************" << endl;
  nextPatient->write(cout);
  cout << "Estimated Wait Time: " << getWaitTime(*nextPatient) << endl;
  cout << "******************************************" << endl << endl;
}
void PreTriage::admit() {
  int menuSelection = -1;
  m_pMenu >> menuSelection;

  char nextType = 0;

  switch (menuSelection) {
  case 1:
    nextType = 'C';
    break;
  case 2:
    nextType = 'T';
    break;
  case 0:
    return;
  }

  int nextPatientIndex = indexOfFirstInLine(nextType);

  if (nextPatientIndex == -1) {
    return;
  }

  cout << endl << "******************************************" << endl;
  m_lineup[nextPatientIndex]->fileIO(false);
  cout << "Calling for ";
  m_lineup[nextPatientIndex]->write(cout);
  cout << "******************************************" << endl << endl;

  setAverageWaitTime(*m_lineup[nextPatientIndex]);
  removePatientFromLineup(nextPatientIndex);
}
void PreTriage::run(void) {
  int menuSelection = -1;

  while (true) {
    m_appMenu >> menuSelection;
    switch (menuSelection) {
    case 0:
      return;
    case 1:
      reg();
      break;
    case 2:
      admit();
      break;
    }
  }
}
} // namespace sdds