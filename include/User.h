#ifndef _USER_
#define _USER_
#include "Forum.h"
#include <string>

using namespace std;

// Abstract Class, like 'Object' in Java
class User {
public:
  User(){};
  User(Forum *f) : forum(f){};
  virtual void log() = 0;
  string user_id;
  Forum *forum;
};

#endif