#include "caesaralg.h"
#include <iostream>

char CaesarAlgorithm::determine_letter(char letter, int shift) {
  shift %= 26;
  if(letter > 64 && letter < 91) {
    letter = determine_caps(letter, shift);
  }
  if(letter > 96 && letter < 123) {
    letter = determine_smalls(letter, shift);
  }
  return letter;
}

char CaesarAlgorithm::determine_smalls(char letter, int shift) {
  int temp = 0;
    if(shift > 0) {
      letter += shift;
      if(letter > 122) {
        temp = letter - 122;
        letter = 96 + temp;
      }
    }
    if(shift < 0) {
      letter += shift;
      if(letter < 97) {
        temp = 97 - letter;
        letter = 123 - temp;
      }
    }
  return letter;
}

char CaesarAlgorithm::determine_caps(char letter, int shift) {
  int temp = 0;
    if(shift > 0) {
      letter += shift;
      if(letter > 90) {
        temp = letter - 90;
        letter = 64 + temp;
      }
    }
    if(shift < 0) {
      letter += shift;
      if(letter < 65) {
        temp = 65 - letter;
        letter = 91 - temp;
      }
    }
  return letter;
}

std::string CaesarAlgorithm::cypher(std::string& text, int shift) {
  std::string result = "";
  for(unsigned int i = 0; i < text.length(); ++i) {
      char x;
      x = determine_letter((char)text[i], shift);
      result += x;
  }
  return result;
}


