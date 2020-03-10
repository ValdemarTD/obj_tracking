#pragma once

#include <string>
#include "./distribution_struct.h"

using namespace std;

typedef struct ObjStruct{
  //Specifies whether integer or string based identifiers are used. 0 for int, 1 for string
  int key_type;

  string obj_class;

  //Numeric identifier. Key type is holdover from previous attempt involving unions. Will fix later. 
  int key;

  //Position, orientation, and placeholder variable for object distribution information
  double position[3];
  double orientation[3];
  DistributionStruct obj_distribution;

} ObjStruct;
