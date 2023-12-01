#ifndef _DATE_SHEET_
#define _DATE_SHEET_
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Date_sheet {
protected:
  string sub;
  int day, month, year;
  string starting_time, ending_time;

public:
  void view_date_sheet();
};

#endif