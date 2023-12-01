#ifndef _CHECK_
#define _CHECK_
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Check {
private:
  string student_name;
  string student_email;
  string student_class;
  int student_rollNO;
  string student_passwd;
  bool found = false;

public:
  bool check_class(string cla);
  bool check_student(int roll, string pass);
  bool check_teacher(int roll, string pass);
  string check_subject(int teach_no);
};

#endif