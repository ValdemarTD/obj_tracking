#pragma once

#include "./obj_struct.h"
#include <string>
#include <vector>

using namespace std;


class ObjHashMap{
private:
  int hash_type = 0;
  vector<ObjStruct*> obj_map[10];
  int _hash_func(int, int);
public:
  void add(ObjStruct*);
  void remove(ObjStruct*);
  ObjStruct* find_by_id(int);
  void write_h_map_to_file(string);
  void read_h_map_from_file(string);
  void clear_map();
};
