#include "HashMap.h"
#include "../include/obj_hash_map.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void ObjHashMap::add(ObjStruct &obj){
  if(obj.key_type == this->hash_type){
    this->obj_map.put(obj.key, obj);
  }
}

void ObjHashMap::remove(ObjStruct &obj){
  if(obj.key_type == this->hash_type){
    this->obj_map.remove(obj.key);
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

}

void ObjHashMap::read_h_map_from_file(string filename){

}
