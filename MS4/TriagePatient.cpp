/*
Final Project Milestone 4
Module    TriagePatient
Filename  TriagePatient.cpp
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
#include "TriagePatient.h"
#include <cstring>
#include <string>
using namespace std;
namespace sdds {
int nextTriageTicket = 1;
TriagePatient::TriagePatient() : Patient(nextTriageTicket++) {}
char TriagePatient::type() const { return 'T'; }
ostream &TriagePatient::csvWrite(ostream &ostr) const {
  Patient::csvWrite(ostr) << ',' << mSymptoms;
  return ostr;
}
istream &TriagePatient::csvRead(istream &istr) {
  delete[] mSymptoms;
  Patient::csvRead(istr);
  istr.ignore(1000, ',');

  string symptomField = "";
  getline(istr, symptomField, '\n');

  mSymptoms = new char[symptomField.length() + 1];
  strcpy(mSymptoms, symptomField.c_str());

  nextTriageTicket = number() + 1;
  return istr;
}
ostream &TriagePatient::write(ostream &ostr) const {
  if (fileIO()) {
    csvWrite(ostr);
    return ostr;
  }

  ostr << "TRIAGE" << endl;
  Patient::write(ostr) << endl;
  ostr << "Symptoms: " << mSymptoms << endl;

  return ostr;
}
istream &TriagePatient::read(istream &istr) {
  if (fileIO()) {
    csvRead(istr);
    return istr;
  }

  delete[] mSymptoms;
  Patient::read(istr);
  cout << "Symptoms: ";

  string symptomField = "";
  getline(istr, symptomField, '\n');

  mSymptoms = new char[symptomField.length() + 1];
  strcpy(mSymptoms, symptomField.c_str());

  return istr;
}
TriagePatient::~TriagePatient() { delete[] mSymptoms; }
} // namespace sdds