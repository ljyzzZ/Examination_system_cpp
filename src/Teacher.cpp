#include "../include/Teacher.h"

Teacher::Teacher(Forum *f) : User(f) {}

void Teacher::log() {
  int teacher_no;
  string teacher_pass;
  cout << "Enter Teacher No : ";
  cin >> teacher_no;
  cout << "Enter Password : ";
  cin >> teacher_pass;
  user_id = to_string(teacher_no);
  login(teacher_no, teacher_pass);
}

void Teacher::login(int user, string passwd) {
  int ret = 0;
  teacher_record = user;
  if (Check::check_teacher(user, passwd)) {
  teach_menu:
    do {
      system("cls");
      cout << "WELCOME TEACHERS..." << endl;
      cout << "Press\n1.To Make paper \n";
      cout << "2.To Check paper \n";
      cout << "3.To View DateSheet\n4.To back to main Menu ";
      cin >> choice;
      char r;
      switch (choice) {
      case 1:
        system("cls");
        Paper::make_paper();
        cout << "\nPress Any key to Go back :- ";
        cin >> r;
        goto teach_menu;
        break;
      case 2:
        system("cls");
        check_paper();
        cout << "\nPress Any key to Go back :- ";
        cin >> r;
        goto teach_menu;
        break;
      case 3:
        system("cls");
        Date_sheet::view_date_sheet();
        cout << "\nPress Any key to Go back :- ";
        cin >> r;
        goto teach_menu;
        break;
      case 4:
        break;
      default:
        cout << "INVALID CHOICE" << endl;
        cout << "press [1] to try again";
        cin >> ret;
        while (cin.fail()) {
          cout << "\nIllegal input! Please enter an Integer:" << endl;
          cin.clear();
          cin.ignore();
          cin >> ret;
        }
        break;
      }
    } while (ret == 1);
  } else {
    cout << "Teacher No Not found. Ask Admin to register You and try "
            "again. You'll back to the Main Menu in 5 seconds.\nThanks...";
    Sleep(5000);
  }
  return;
}

void Teacher::check_paper() {
  string name, email, class_no, pas;
  int roll;
  ifstream ans_sht, file;
  ofstream res;
  string sno, ans;
  string temp_subject;
  file.open("bin/student.txt");
  res.open("result.txt", ios::app);
  if (!file) {
    cout << "Something went wrong. Try again...";
  }
  // get the subject name(like PF1011) taught by this teacher
  string subj = Check::check_subject(teacher_record);
  cout << "Check Paper of " << subj << endl;
  cout << "Select Student To Check his/her Paper : " << endl;
  while (file >> name >> email >> class_no >> roll >> pas) {
    cout << "Name : " << name << ";\t\tRoll Number : " << roll << endl;
  }
  file.close();
  cout << "\nEnter Roll Number to Check : " << endl;
  cin.ignore(10, '\n');
  cin >> check_roll;

  if (Check::check_student(check_roll, pas)) {
    for (int i = 0; i <= 5; i++) {
      if (subj == subject[i]) {
        temp_subject = subject[i];
        ans_sht.open(Ans_sheet[i]);
        if (!ans_sht) {
          cout << "Something went wrong. Try again..." << endl;
        }
        int j = 0;
        while (!ans_sht.eof()) {
          getline(ans_sht, sno);
          getline(ans_sht, ans);
          if (sno == to_string(check_roll)) {
            j++;
            cout << "Answer of Question :" << j << endl << ans << endl;
          }
        }
        cout << "Enter The Total marks for this student : ";
        cin >> obtained_marks;
        res << temp_subject << " " << check_roll << " " << obtained_marks
            << endl;
        res.close();
        ans_sht.close();
        break;
      }
    }
  } else {
    cout << "please enter correct roll no. Press Any key to go back";
  }
}