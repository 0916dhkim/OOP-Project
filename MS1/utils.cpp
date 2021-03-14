/*
Final Project Milestone 1
Module    utils
Filename  utils.cpp
Version   1.0
Author    Donghyeon Kim
Revision History
--------------------------------------------------
Date        Reason
2021/03/14  Preliminary release.
--------------------------------------------------
I have done all the coding by myself and only
copied the code that my professor provided to
complete my workshops and assignments.
--------------------------------------------------*/
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS
#include "Time.h"
#include "utils.h"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <limits>
#include <string>
using namespace std;
namespace sdds {
bool debug = false; // made global in utils.h
int getTime() {
  int mins = -1;
  if (debug) {
    Time t(0);
    cout << "Enter current time: ";
    do {
      cin.clear();
      cin >> t; // needs extraction operator overloaded for Time
      if (!cin) {
        cout << "Invlid time, try agian (HH:MM): ";
        cin.clear();
      } else {
        mins = int(t);
      }
      cin.ignore(1000, '\n');
    } while (mins < 0);
  } else {
    time_t t = time(NULL);
    tm lt = *localtime(&t);
    mins = lt.tm_hour * 60 + lt.tm_min;
  }
  return mins;
}

int getInt(int min, int max, const char *prompt, const char *errorMessage,
           bool showRangeAtError) {
  int ret = 0;
  string extras = "";
  bool complete = false;

  if (prompt != nullptr)
    cout << prompt;

  do {
    cin >> ret;
    bool inputSuccess = cin.good();
    cin.clear();
    getline(cin, extras);
    complete = cin && extras == "" && min <= ret && ret <= max;
    if (!inputSuccess) {
      cout << "Bad integer value, try again: ";
    } else if (extras != "") {
      cout << "Enter only an integer, try again: ";
    } else if (min > ret || max < ret) {
      cout << errorMessage;
      if (showRangeAtError) {
        cout << "[" << min << " <= value <= " << max << "]: ";
      }
    }
  } while (!complete);

  return ret;
}

int getInt(const char *prompt) {
  return getInt(numeric_limits<int>::min(), numeric_limits<int>::max(), prompt,
                "", false);
}

char *getcstr(const char *prompt, // User entry prompt
              std::istream &istr, // the Stream to read from
              char delimiter      // Delimiter to mark the end of data
) {
  string line;
  char *ret;

  // Prompt
  if (prompt != nullptr)
    cout << prompt;

  // Get input.
  getline(istr, line, delimiter);

  ret = new char[line.length() + 1];
  strcpy(ret, line.c_str());

  return ret;
}
} // namespace sdds
