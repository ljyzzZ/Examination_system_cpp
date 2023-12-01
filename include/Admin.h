#ifndef _ADMIN_
#define _ADMIN_
#include "Check.h"
#include "Constant.h"
#include "Date_sheet.h"
#include "User.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Admin : public User, public Check, public Date_sheet {
private:
  // admin credentials:
  const string admin_username = "admin";
  const string admin_password = "123";

  // for File IO
  string student_name;
  string student_email;
  string student_class;
  int student_rollNO;

  int choice;
  bool isFound = false;
  string Class;

  string teacher_name;
  string teacher_email;
  int teach_Code;

public:
  Admin(){};
  Admin(Forum *f);

  void make_date_sheet();

  void add_student();

  void add_teacher();

  void log();

  void login(string user, string pass);
};

#endif