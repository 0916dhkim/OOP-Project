/*
Final Project Milestone 1
Module    Menu
Filename  Menu.h
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
#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds {

class Menu {
  char *m_text{nullptr}; // holds the menu content dynamically
  int m_noOfSel{-1}; // holds the number of options displayed in menu content
  void display() const;

public:
  Menu(const char *MenuContent, int NoOfSelections);
  virtual ~Menu();
  int &operator>>(int &Selection);
  // add safe copying logic
  Menu(const Menu &);
  Menu &operator=(const Menu &) = delete;
};
} // namespace sdds

#endif
