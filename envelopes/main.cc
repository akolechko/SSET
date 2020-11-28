#include <iostream>
#include "validation.h"

int main() {
  std::string str;
  while (1) {
    std::getline(std::cin, str);
    if (IsValid<double>(str))
      std::cout << "Valid!" << std::endl;
    else
      std::cout << "Invalid!" << std::endl;
  }

  return 0;
}