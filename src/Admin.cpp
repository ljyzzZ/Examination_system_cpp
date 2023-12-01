#include "../include/Admin.h"

Admin::Admin(Forum *f) : User(f) {}

void Admin::make_date_sheet() {
  int ret = 0;
  do {
    system("cls");
    cout << "\t\t\t----------Welcome admin----------- \n\n";
    cout << "\t\tMake Date sheet \n";
    cout << "Enter the class Name :";
    cin >> Class;

    ofstream date_sheet;
    date_sheet.open("bin/date_sheet.txt");
    if (!date_sheet) {
      cout << "File Not Found or permission denied.";
    }
    for (int i = 0; i < 5; i++) {
      cout << "For " << subject[i] << " : " << endl;
      cout << "Enter Date (DD-MM-YYYY) :\n";
      cout << "Enter Date : ";
      cin >> day;
      cout << "Enter Month: ";
      cin >> month;
      cout << "Enter Year: ";
      cin >> year;
      cout << "Enter Time";
      cout << "Enter Starting time : ";
      cin >> starting_time;
      cout << "Enter Ending Time : ";
      cin >> ending_time;

      date_sheet << subject[i] << " " << day << " " << month << " " << year
                 << " " << starting_time << " " << ending_time << " ";
    }
    cout << "Enter [1] to make another Date sheet else return." << endl;
    cin >> ret;
    while (cin.fail()) {
      cout << "\nIllegal input! Please enter an Integer:" << endl;
      cin.clear();
      cin.ignore();
      cin >> ret;
    }
  } while (ret == 1);
  return;
}

void Admin::add_student() {
  int ret = 0;
  do {
    cout << "\t\tAdd Students \n";
    cout << "Enter Student Name: ";
    cin >> student_name;
    cout << "Enter student email: ";
    cin >> student_email;
    cout << "Enter student class: ";
    cin >> student_class;
    cout << "Enter student Roll No.: ";
    cin >> student_rollNO;

    ofstream Add_student;
    Add_student.open("bin/student.txt", ios::app);
    if (!Add_student) {
      cout << "File Not Found or permission denied.";
    } else {
      Add_student << student_name << " " << student_email << " "
                  << student_class << " " << student_rollNO << " "
                  << student_rollNO << "\n"; // 第二个rollNo是默认密码为学号
    }

    Add_student.close();

    cout << "Enter [1] to add another student, else return." << endl;
    cin >> ret;
    while (cin.fail()) {
      cout << "\nIllegal input! Please enter an Integer:" << endl;
      cin.clear();
      cin.ignore();
      cin >> ret;
    }
  } while (ret == 1);
  cin.ignore();
  return;
}

void Admin::add_teacher() {
  int ret = 0;
  do {
    system("cls");

    cout << "Enter Teacher Name: ";
    cin >> teacher_name;
    cout << "Enter Teacher email: ";
    cin >> teacher_email;
    cout << "Enter Teacher Subject: ";

    for (int i = 0; i <= 5; i++) {
      cout << "Press " << i << " For subject: " << subject[i] << endl;
    }
    int ch;
    cin >> ch;

    cout << "Enter Teacher Code : ";
    cin >> teach_Code;

    ofstream teacher;
    teacher.open("bin/teacher.txt", ios::app);
    if (!teacher) {
      cout << "File Not Found Something went wrong Try again.";
    } else {
      teacher << teacher_name << " " << teacher_email << " " << subject[ch]
              << " " << teach_Code << "\n";
    }

    teacher.close();

    cout << "Enter [1] to add another student else return." << endl;
    cin >> ret;
    while (cin.fail()) {
      cout << "\nIllegal input! Please enter an Integer:" << endl;
      cin.clear();
      cin.ignore();
      cin >> ret;
    }
  } while (ret == 1);
  return;
}

void Admin::log() {
  string admin_name, admin_pass;
  cout << "Enter Username  : ";
  cin >> admin_name;
  cout << "Enter Password : ";
  cin >> admin_pass;
  login(admin_name, admin_pass);
}

void Admin::login(string user, string pass) {
  int ret = 0;
  do {
    system("cls");
    if (user == admin_username && pass == admin_password) {
      cout << "Press\n1.For Add Student \n";
      cout << "2.For Add Teacher \n";
      cout << "3.To Make Date_Sheet \n";
      cout << "4.to Back to main menu\n";
      cin >> choice;
      switch (choice) {
      case 1:
        add_student();
        break;
      case 2:
        add_teacher();
        break;
      case 3:
        make_date_sheet();
        break;
      case 4:
        break;
      default:
        cout << "Invalid Choice! Press [1] to Try Again else Exit..";
        cin >> ret;
        while (cin.fail()) {
          cout << "\nIllegal input! Please enter an Integer:" << endl;
          cin.clear();
          cin.ignore();
          cin >> ret;
        }
        break;
      }
    } else {
      cout << "Wrong username/password! Press any key to back to the menu."
           << endl;
      char i;
      cin >> i;
    }
  } while (ret == 1);
}
