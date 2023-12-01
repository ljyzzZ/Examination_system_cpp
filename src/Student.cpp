#include "../include/Student.h"

Student::Student(Forum *f) : User(f){};

void Student::log() {
  int student_no;
  string student_pass;
  cout << "Enter Student No : ";
  cin >> student_no;
  cout << "Enter Password : ";
  cin >> student_pass;
  user_id = to_string(student_no);
  login(student_no, student_pass);
}

void Student::give_paper() {
  cout << "Welcome To Give Your Paper " << endl;
  cout << "Select Subject : " << endl;
  for (int i = 0; i <= 4; i++) {
    cout << "Press " << i + 1 << " For " << subject[i] << endl;
  }
  int ch;
  cin >> ch;

  if (ch > 0 && ch < 7) {
    ifstream file;
    ofstream ans;
    file.open(file_of_papers[ch - 1]);
    ans.open(Ans_sheet[ch - 1], ios::app);
    if (!file || !ans) {
      cout << "Something went wrong. Try again..." << endl;
      if (file)
        file.close();
      if (ans)
        ans.close();
    } else {
      string ques;
      string mark;
      ans << valid << endl;
      cin.ignore();
      while (!file.eof()) {
        file >> ques >> mark;
        cout << "Q : " << ques << "\t\t\t Marks : " << mark << endl;
        cout << "Ans (limit in 256 letters): " << endl;
        cin.getline(answer, 256);
        cout << "\nYour Answer:\n" << answer << endl;
        ans << user_id << endl << answer << endl;
      }
      ans.close();
      file.close();
    }
  }
}

void Student::login(int user, string passwd) {
  int ret = 0;
  valid = user;
  if (Check::check_student(user, passwd)) {
  st_menu:
    do {
      system("cls");
      cout << "WELCOME Student " << user << endl;
      cout << "Press\n1. To View Date_sheet \n";
      cout << "2. To Give Paper \n";
      cout << "3. To View Results\n";
      cout << "4. To Browse Discussions" << endl;
      cout << "5. To back to main Menu" << endl;
      cin >> choice;
      char r;
      switch (choice) {
      case 1:
        system("cls");
        Date_sheet::view_date_sheet();
        cout << "\nPress Any key to Go back :- " << endl;
        cin >> r;
        goto st_menu;
        break;
      case 2:
        system("cls");
        give_paper();
        cout << "\nPress Any key to Go back :- " << endl;
        cin >> r;
        goto st_menu;
        break;
      case 3:
        system("cls");
        view_grades();
        cout << "\nPress Any key to go back :- " << endl;
        cin >> r;
        goto st_menu;
        break;
      case 4:
        forum->setUserId(user_id);
        forum->forumMenu();
        forum->savePosts();
        break;
      case 5:
        break;
      default:
        cout << "INVALID CHOICE" << endl;
        cout << "press [1] to try again, else back to the menu";
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
    cout << "Roll No Not found. Ask Admin to register You and try "
            "again.\nPress Any key to go back :)";
    char r;
    cin >> r;
  }
  return;
}

void Student::view_grades() {
  bool isFound = false;
  int choice;
  string sub;
  int rs, grades;
  cout << "Select Subject to View your result : " << endl;
  for (int i = 0; i <= 4; i++) {
    cout << "Press " << i + 1 << " to " << subject[i] << endl;
  }
  cin >> choice;
  choice--;
  if (choice >= 0 && choice < 5) {
    ifstream res;
    res.open("result.txt");
    int stu_grade;
    int sum = 0;
    int number = 0;
    while (!res.eof()) {
      res >> sub >> rs >> grades;
      if (sub == subject[choice]) {
        if (valid == rs) {
          stu_grade = grades;
          isFound = true;
        }
        sum += grades;
        number++;
      }
    }
    if (!isFound) {
      cout << "\nPaper is not checked Yet. \n";
    } else {
      cout << "Your Total Marks of subject " << subject[choice]
           << " is : " << stu_grade << endl;
      cout << "The Average Marks of subject " << subject[choice]
           << " is : " << (float)sum / (float)number << endl;
    }
    res.close();
  }
}