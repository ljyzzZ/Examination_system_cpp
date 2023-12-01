#include "include/Admin.h"
#include "include/Check.h"
#include "include/Constant.h"
#include "include/Date_sheet.h"
#include "include/Forum.h"
#include "include/Paper.h"
#include "include/Student.h"
#include "include/Teacher.h"
#include "include/User.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void menu() {
  User *usr;
  // Forum *forum = new Forum;
  int choice;
  int ret = 1;
  do {
    system("cls");
    cout << "==========\t\t\t\tEXAM PORTAL\t\t\t\t=========\nPress\n";

    cout << "1. For Admin" << endl;
    cout << "2. For Student" << endl;
    cout << "3. For Teacher" << endl;
    cout << "4. To Exit" << endl;
    cout << "Select : ";
    cin >> choice;
    switch (choice) {
    case 1:
      usr = new Admin();
      usr->log();
      break;
    case 2:
      usr = new Student();
      usr->log();
      break;
    case 3:
      usr = new Teacher();
      usr->log();
      break;
    case 4:
      cout << "\n\tThanks for Using.\n";
      exit(1);
    default:
      cout << "Invalid Choice! Press [1] to Try Again, else Exit." << endl;
      cin >> ret;
      while (cin.fail()) {
        cout << "Illegal input! Please enter an Integer(Press [1] to Try "
                "Again):"
             << endl;
        cin.clear();
        cin.ignore();
        cin >> ret;
      }
      break;
    }
  } while (ret == 1);
}
#include <chrono>
#include <ctime>
#include <iomanip>
int main() {
  menu();
  system("pause");
  return 0;
}