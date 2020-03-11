#include "../include/obj_hash_map.h"
#include "../include/iohelper.h"
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int ObjHashMap::_hash_func(int key, int type){
  if(type == 0){
    return key % 10;
  }
  return -1;
}

void ObjHashMap::add(ObjStruct* obj){
  if(obj->key_type == this->hash_type){
    int bucket = this->_hash_func(obj->key, obj->key_type);
    if(bucket >= 0){
      this->obj_map[bucket].push_back(obj);
    }
  }
}

void ObjHashMap::remove(ObjStruct* obj){
  if(obj->key_type == this->hash_type){
    int bucket = this->_hash_func(obj->key, obj->key_type);
    //erase-remove idiom to remove the object from our objects vector
    for(int i = 0; i < this->obj_map[bucket].size(); i++){
      if(this->obj_map[bucket][i]->key == obj->key){
        this->obj_map[bucket].erase(this->obj_map[bucket].begin() + i);
      }
    }
  }
}

ObjStruct* ObjHashMap::find_by_id(int key){
  ObjStruct obj;
  int bucket = this->_hash_func(key, 0);
  for(int i = 0; i < this->obj_map[bucket].size(); i++){
    if(this->obj_map[bucket][i]->key == key){
      return this->obj_map[bucket][i];
    }
  }

  return NULL;
}

void ObjHashMap::write_h_map_to_file(string filename){
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < this->obj_map[i].size(); j++){
      string to_write = string_from_struct(this->obj_map[i][j]);
      write_string(to_write, filename, false);
    }
  }
}

void ObjHashMap::read_h_map_from_file(string filename){
  fstream file_reader;
  file_reader.open(filename, fstream::in);
  if(!file_reader.is_open()){
    return;
  }
  string new_line;
  while(getline(file_reader, new_line)){
    #if DEBUG
      cout << "Line is: " << new_line << endl;
    #endif
    ObjStruct* new_obj = struct_from_string(new_line);
    this->add(new_obj);
  }
  file_reader.close();
}

void ObjHashMap::clear_map(){
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < this->obj_map[i].size(); j++){
      delete this->obj_map[i][j];
      this->obj_map[i].erase(this->obj_map[i].begin() + j);
    }
  }
}
