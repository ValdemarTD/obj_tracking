#pragma once

#include <string>
#include "./distribution_struct.h"

typedef struct ObjStruct{
  //Specifies whether integer or string based identifiers are used. 0 for int, 1 for string
  int key_type;

  string obj_class;

  //Allows for use of string-based or number-based identifiers. Should be unique.
  union{int numeric_identifier;
        std::string str_identifier;
      }key;

  //Position, orientation, and placeholder variable for object distribution information
  double position[3];
  double orientation[3];
  DistributionStruct obj_distribution;

} ObjStruct;
