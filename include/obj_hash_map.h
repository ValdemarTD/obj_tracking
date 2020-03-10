#pragma once

#include "HashMap.h"
#include "./obj_struct.h"
#include <string>

using namespace std;

struct IntHash {
  unsigned long operator()(const int& k) const
  {
    return k % 10;
  }
};

class ObjHashMap{
private:
  HashMap<int, ObjStruct, 10, struct IntHash> obj_map;
  int hash_type = 0;
  vector<string> keys;
public:
  void add(ObjStruct&);
  void remove(ObjStruct&);
  ObjStruct* find_by_id(int);
  void write_h_map_to_file(string);
  void read_h_map_from_file(string);
};
