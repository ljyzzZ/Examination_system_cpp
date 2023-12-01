#ifndef _TEACHER_
#define _TEACHER_
#include "Check.h"
#include "Constant.h"
#include "Date_sheet.h"
#include "Paper.h"
#include "User.h"
#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Teacher : public User, public Check, public Date_sheet, public Paper {
private:
  int choice;
  int teacher_record;
  int check_roll;
  int obtained_marks;

public:
  Teacher(){};
  Teacher(Forum *f);

  void log();

  void login(int user, string passwd);

  // 查看学生试卷答案并评分
  void check_paper();
};
#endif