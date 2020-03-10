#include "../include/obj_hash_map.h"
#include "../include/iohelper.h"
#include <string>
#include <fstream>

using namespace std;

int main(){
  string f_in = "../data/test_input.txt";
  string f_out = "../data/test_output.txt";
  ObjHashMap hmap;

  hmap.read_h_map_from_file(f_in);
  hmap.write_h_map_to_file(f_out);

  return(0);
}
