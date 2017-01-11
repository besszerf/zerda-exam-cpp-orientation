#include <iostream>
#include "caesaralg.h"
#include "filehandler.h"
#include <string>
#include <cstdlib>
using namespace std;


int main(int argc, char* argv[]) {
  if (argc == 1) {
    std::cout << "No filename is provided." << std::endl;
    return 0;
  }
  std::string arg1 = argv[1];
  if (arg1 == "-s" || arg1 == "-o") {
    std::cout << "No filename is provided." << std::endl;
  }
  FileHandler fh(arg1);
  std::string in_file_content = fh.read_file();
  if(in_file_content == "Could not open the file.") {
    std::cout << in_file_content << std::endl;
    return 0;
  }
  if(argc < 4){
    std::cout << "No shift is provided." << std::endl;
    return 0;
  }
  if (argc > 3 && argc < 5) {
    std::string arg2 = argv[2];
    if(arg2 != "-s") {
      std::cout << "Invalid arguments." << std::endl;
      return 0;
    } else {
      int shift = atoi(argv[3]);
      if(shift == 0) {
        std::cout << in_file_content << std::endl;
      } else {
        CaesarAlgorithm ca;
        std::cout << ca.cypher(in_file_content, shift);
      }
    }
  }
  if(argc < 6){
    std::string arg2 = argv[2];
    std::string arg3 = argv[3];
    std::string arg4 = argv[4];
    if(arg2 == "-s" && (arg3 != "-o" && arg4 != "-o")) {
      int shift = atoi(argv[3]);
      if(shift == 0) {
        std::cout << in_file_content << std::endl;
      } else {
        CaesarAlgorithm ca;
        std::cout << ca.cypher(in_file_content, shift);
      }
    }
    if(arg2 == "-s" && arg3 == "-o") {
      std::cout << "No shift is provided." << std::endl;
      return 0;
    }
    if(arg2 == "-s" && arg4 == "-o") {
      std::cout << "No output file is provided." << std::endl;
      return 0;
    }
  }
  if(argc < 7){
    std::string arg2 = argv[2];
    std::string arg3 = argv[3];
    std::string arg4 = argv[4];
    std::string arg5 = argv[5];

    bool is_shift_flag = false;
    bool is_out_file_flag = false;
    int shift;
    std::string out_file_name = "";
      if(arg2 == "-s") {
        is_shift_flag = true;
        shift = atoi(arg3.c_str());
      }
      if(arg4 == "-o") {
        is_out_file_flag = true;
        out_file_name = arg5;
      }
      if(arg2 == "-o") {
        is_out_file_flag = true;
        out_file_name = arg3;
      }
      if(arg4 == "-s") {
        is_shift_flag = true;
        shift = atoi(arg5.c_str());
      }
    if(!is_shift_flag || !is_out_file_flag) {
      std::cout << "Invalid arguments." << std::endl;
    } else {
      CaesarAlgorithm ca;
      std::string cyphered = ca.cypher(in_file_content, shift);
      fh.set_file(out_file_name);
      fh.print_to_file(cyphered);
    }
  }
  return 0;
}

