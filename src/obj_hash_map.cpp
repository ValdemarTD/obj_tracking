#include "HashMap.h"
#include "../include/obj_hash_map.h"
#include "../include/iohelper.h"
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void ObjHashMap::add(ObjStruct &obj){
  if(obj.key_type == this->hash_type){
    this->obj_map.put(obj.key, obj);
    this->keys.push_back(obj.key);
  }
}

void ObjHashMap::remove(ObjStruct &obj){
  if(obj.key_type == this->hash_type){
    this->obj_map.remove(obj.key);

    //erase-remove idiom to remove the key from out keys vector
    this->keys.erase(remove(this->keys.begin(), this->keys.end(), obj.key), this->keys.end());
  }
}

ObjStruct* ObjHashMap::find_by_id(int key){
  ObjStruct obj;
  if(this->obj_map.get(key, obj)){
    return &obj;
  }
  return NULL;
}

void ObjHashMap::write_h_map_to_file(string filename){
  for(int i = 0; i < this->keys.size(); i++){
    ObjStruct* obj = this->find_by_id(this->keys[i]);
    if(obj == NULL){
      continue;
    }
    string to_write = string_from_struct(*obj);
    write_string(to_write, filename, false);
  }
}

void ObjHashMap::read_h_map_from_file(string filename){
  fstream file_reader;
  file_reader.open(filename, fstream::in);
  if(!file_reader.is_open()){
    return;
  }
  while(!file_reader.eof()){
    string new_line = file_reader.getline();
    ObjStruct* new_obj = struct_from_string(new_line);
    this->add(*new_obj);
  }
  file_reader.close();
}
