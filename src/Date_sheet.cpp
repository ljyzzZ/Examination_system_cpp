#include "../include/Date_sheet.h"

void Date_sheet::view_date_sheet() {
  ifstream file;
  file.open("bin/date_sheet.txt");

  if (!file) {
    cout << "File Not Found ";
  }
  cout << "\n\t\t\t\t------DateSheet-----\n\n";
  while (file >> sub >> day >> month >> year >> starting_time >> ending_time) {
    cout << "Subject : " << sub << "\tDate : " << day << "-" << month << "-"
         << year << "\t\tStarting Time : " << starting_time
         << " \t\tEnding Time : " << ending_time << endl;
  }

  file.close();
}