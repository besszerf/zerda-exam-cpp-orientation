#ifndef CAESARALG_H_
#define CAESARALG_H_
#include <string>

class CaesarAlgorithm {
  public:
    std:: string cypher(std::string& text, int shift);
  private:
    char determine_letter(char letter, int shift);
    char determine_smalls(char letter, int shift);
    char determine_caps(char letter, int shift);

};



#endif /* CAESARALG_H_ */
