#ifndef RecommendCharacter_h
#define RecommendCharacter_h
#include <string.h>
#include <iostream>
#include "Human.h"

using namespace std;

struct question {
  string questionText;
  string option1;
  string option2;
  string option3;
  string option4;
  string option5;
  string option6;
  string option7;
};

static Human* Login();

#endif /* RecommendCharacter_h */
