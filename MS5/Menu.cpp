/*
Final Project Milestone 1
Module    Menu
Filename  Menu.cpp
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
#include "Menu.h"
#include "utils.h"
#include <cstring>
#include <iostream>

using namespace std;
using namespace sdds;

Menu::Menu(const char *MenuContent, int NoOfSelections) {
  if (MenuContent == nullptr || NoOfSelections < 0) {
    // Invalid arguments.
    return;
  }

  m_text = new char[strlen(MenuContent) + 1];
  strcpy(m_text, MenuContent);

  m_noOfSel = NoOfSelections;
}

Menu::Menu(const Menu &other) {
  if (other.m_text == nullptr) {
    // Invalid argument.
    return;
  }

  m_text = new char[strlen(other.m_text) + 1];
  strcpy(m_text, other.m_text);

  m_noOfSel = other.m_noOfSel;
}

Menu::~Menu() { delete[] m_text; }

void Menu::display() const {
  cout << m_text << endl;
  cout << "0- Exit" << endl;
}

int &Menu::operator>>(int &Selection) {
  display();
  Selection = getInt(0, m_noOfSel, "> ", "Invalid option ");

  return Selection;
}
