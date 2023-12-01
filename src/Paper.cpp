#include "../include/Paper.h"
#include "../include/Constant.h"

void Paper::make_paper() {
  cout << "Make Paper \n";
  cout << "Select Subject : " << endl;
  for (int i = 0; i <= 4; i++) {
    cout << "Press " << i + 1 << " For " << subject[i] << endl;
  }
  cout << "==> ";
  int ch;
  cin >> ch;

  if (ch > 0 && ch < 7) {

    cout << "Enter total number of Questions : ";
    cin >> total_qes;
    cout << "Total Time Allowed(in minutes) : ";
    cin >> time_allowed;
    cout << "Enter Question : \n";

    ofstream paper;
    paper.open(file_of_papers[ch - 1]);
    if (!paper) {
      cout << "Something went wrong. Try again...";
    }
    // paper << subject[ch-1] << " " << time_allowed << " " << endl;

    for (int i = 0; i < total_qes; i++) {

      cout << "Q" << i + 1 << " : ";
      cin.ignore();
      cin.getline(question, 256);
      cout << "Enter marks for this Question : ";
      cin >> each_marks;
      paper << question << endl;
      paper << each_marks << endl;

      total_marks += each_marks;
    }

    cout << "Total marks : " << total_marks << endl;
    paper.close();
  } else {
    cout << "class Not found" << endl;
  }
}