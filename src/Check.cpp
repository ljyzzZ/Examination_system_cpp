#include "../include/Check.h"

bool Check::check_class(string cla) {
  fstream file;
  file.open("bin/student.txt", ios::in);
  if (!file) {
    cout << "Something went wrong Try again...";
  }
  while (!file.eof()) {
    file >> student_name >> student_email >> student_class >> student_rollNO >>
        student_passwd;
    if (cla == student_class) {
      found = true;
      break;
    }
  }
  return found;
}

bool Check::check_student(int roll, string pass) {
  fstream file;
  file.open("bin/student.txt", ios::in);
  if (!file) {
    cout << "Something went wrong Try again...";
  }
  while (!file.eof()) {
    file >> student_name >> student_email >> student_class >> student_rollNO >>
        student_passwd;
    if (roll == student_rollNO && pass == student_passwd) {
      found = true;
      break;
    }
  }
  return found;
}

bool Check::check_teacher(int roll, string pass) {
  fstream file;
  file.open("bin/teacher.txt", ios::in);
  if (!file) {
    cout << "Something went wrong Try again...";
  }
  while (!file.eof()) {
    file >> student_name >> student_email >> student_class >> student_rollNO >>
        student_passwd;
    if (roll == student_rollNO && pass == student_passwd) {
      found = true;
      break;
    }
  }
  return found;
}

string Check::check_subject(int teach_no) {
  string subj;
  fstream file;
  file.open("bin/teacher.txt", ios::in);
  if (!file) {
    cout << "Something went wrong Try again...";
  }
  while (!file.eof()) {
    file >> student_name >> student_email >> student_class >> student_rollNO >>
        student_passwd;
    if (teach_no == student_rollNO) {
      subj = student_class;
      break;
    }
  }
  return subj;
}