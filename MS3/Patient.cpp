/*
Final Project Milestone 3
Module    Patient
Filename  Patient.cpp
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
#include "Patient.h"
#include "utils.h"
#include <cstring>

using namespace sdds;
using namespace std;

Patient::Patient(int ticketNumber, bool isFile)
    : m_ticket(ticketNumber), m_isfile(isFile) {}

Patient::~Patient() { delete[] m_name; }

bool Patient::fileIO() const { return m_isfile; }

void Patient::fileIO(bool value) { m_isfile = value; }

bool Patient::operator==(char type) const { return type == this->type(); }

bool Patient::operator==(const Patient &other) const {
  return type() == other.type();
}

void Patient::setArrivalTime() { m_ticket.resetTime(); }

Patient::operator Time() const { return m_ticket; }

int Patient::number() const { return m_ticket.number(); }

ostream &Patient::csvWrite(ostream &ostr) const {
  ostr << type() << ',' << m_name << ',' << m_ohip << ',';
  m_ticket.csvWrite(ostr);

  return ostr;
}

istream &Patient::csvRead(istream &istr) {
  string s;
  getline(istr, s, ',');

  delete[] m_name;
  m_name = new char[s.length() + 1];
  strcpy(m_name, s.c_str());

  istr >> m_ohip;
  istr.ignore(1000, ',');

  m_ticket.csvRead(istr);

  return istr;
}

ostream &Patient::write(ostream &ostr) const {
  m_ticket.write(ostr);
  ostr << endl;

  int nameLength = strlen(m_name);
  for (int i = 0; i < nameLength && i < 25; i++) {
    ostr << m_name[i];
  }
  ostr << ", OHIP: " << m_ohip;

  return ostr;
}

istream &Patient::read(istream &istr) {
  if (m_isfile) {
    return csvRead(istr);
  }
  // Get name.
  string s = "";
  cout << "Name: ";
  getline(istr, s);
  delete[] m_name;
  m_name = new char[s.length() + 1];
  strcpy(m_name, s.c_str());

  // Get OHIP.
  cout << "OHIP:";
  m_ohip = getInt(100000000, 999999999, nullptr, "Invalid OHIP Number, ");

  return istr;
}