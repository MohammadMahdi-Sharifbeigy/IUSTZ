#ifndef FileCheck_h
#define FileCheck_h
#include <iostream>
#include <fstream>
#include <string.h>
#include <filesystem>

using namespace std;

bool is_empty(ifstream &pFile);

inline bool exists_test (const std::string& name);

#endif /* FileCheck_h */
