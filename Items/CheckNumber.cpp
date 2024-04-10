#include <iostream>
#include "CheckNumber.h"


using namespace std;

bool check_number(string str) {
        for (int i = 0; i < str.length(); i++)
            if (isdigit(str[i]) == false)
                return false;
    return true;
}