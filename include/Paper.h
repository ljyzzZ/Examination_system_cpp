#ifndef _PAPER_
#define _PAPER_
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Paper {
private:
  int each_marks;
  int total_marks = 0;
  int total_qes;
  char question[555];
  int time_allowed;
  char ans[999];

public:
  void make_paper();
};

#endif