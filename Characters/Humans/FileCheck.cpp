#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include "FileCheck.h"

using namespace std;

bool is_empty(ifstream& pFile){
    return pFile.peek() == ifstream::traits_type::eof();
}

inline bool exists_test (const string& name) {
    ifstream f(name.c_str());
    return f.good();
}