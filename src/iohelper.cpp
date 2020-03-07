#include "../include/iohelper.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void write_string(string to_write, string filename){
  //placeholder
}

vector<string> parse_by_char(string to_parse, string delimiter){
  vector<string> new_vec;
  while(to_parse.length() > 0){
    new_vec.push_back(to_parse.substr(0, to_parse.find(delimiter)));
    to_parse.erase(0, to_parse.find(delimiter) + delimited.length());
  }
  return new_vec;
}

ObjStruct* struct_from_string(string to_structify){
  ObjStruct* new_obj = new ObjStruct;
  vector<string> full_obj = parse_by_char(to_structify, ' ');
  vector<string> position = parse_by_char(full_obj[2], ',');
  vector<string> orientation = parse_by_char(full_obj[3], ',');
  new_obj->key_type = atoi(full_obj[0]);
  if(new_obj->key_type == 0){
    new_obj->numeric_identifier = atoi(full_obj[1]);
  }
  else{
    strcpy(new_obj->str_identifier, full_obj[1]);
  }
  new_obj->position[0] = atoi(position[0]);
  new_obj->position[1] = atoi(position[1]);
  new_obj->position[2] = atoi(position[2]);

  new_obj->orientation[0] = atoi(orientation[0]);
  new_obj->orientation[1] = atoi(orientation[1]);
  new_obj->orientation[2] = atoi(orientation[2]);

  new_obj->obj_distribution.placeholder = atoi(full_obj[4]);

  return new_obj;
}

string string_from_struct(ObjStruct* obj){
  ostringstream oss;
  /* Makes a string of the format:
   * key_type  key  x,y,z  r,p,yaw  distribution_placeholder
   *
   * Designed to be output in a format readable by struct_from_string()
   */
  oss << obj->key_type << " " << obj->key << " "
      << obj->position[0] << "," << obj->position[1] << ","
      << obj->position[2] << " " << obj->orientation[0]
      << "," << obj->orientation[1] << "," obj->orientation[2]
      << " " << obj->obj_distribution.placeholder << "\n";

  return oss.str();
}
