#pragma once

#define DEBUG 1

#include <string>
#include <vector>
#include "./obj_struct.h"

using namespace std;

void write_string(string, string, bool);
vector<string> parse_by_char(string, string);
ObjStruct* struct_from_string(string);
string string_from_struct(ObjStruct*);
