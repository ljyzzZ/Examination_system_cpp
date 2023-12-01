#ifndef _STUDENT_
#define _STUDENT_
#include "Check.h"
#include "Constant.h"
#include "Date_sheet.h"
#include "Paper.h"
#include "User.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Student : public User, public Check, public Date_sheet, public Paper {
private:
  int valid;
  int choice;
  char answer[256];

public:
  Student(){};
  Student(Forum *f);

  void log();

  void give_paper();

  void login(int user, string passwd);

  void view_grades();
};

#endif