/*
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <iostream>
#include "catch.hpp"
#include "filehandler.h"
#include "caesaralg.h"

FileHandler fh("input.txt");


TEST_CASE("Filehandler gives error message on non existing file") {
FileHandler fh("x.txt");
std::string a;
a = fh.read_file();
REQUIRE(a == "Could not open the file.");
}

TEST_CASE("Filehandler doesn't give error message on existing file") {
std::string a;
a = fh.read_file();
REQUIRE_FALSE(a == "Could not open the file.");
}

TEST_CASE("Filehandler doesn't give error message on existing file") {
std::string a;
a = fh.read_file();
CaesarAlgorithm ca;
std::cout << a;
std::cout << ca.cypher(a, -27);
REQUIRE_FALSE(a == "Could not open the file.");
}

*/
