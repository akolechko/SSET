#include "stdafx.h"

#include "conversion.h"
#include "convertor.h"

using EC = conversion::ErrorCode;

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Number to verbal representation convertor: <number>."
              << std::endl;

    return EXIT_FAILURE;
  }

  long long number = 0;
  EC error_code = conversion::StringToLongLong(argv[1], number);

  if (error_code == EC::kInvalidArgument) {
    std::cout << "Number is invalid." << std::endl;
    return EXIT_FAILURE;
  }

  if (error_code == EC::kOutOfRange) {
    std::cout << "Number is too big." << std::endl;
    return EXIT_FAILURE;
  }

  Convertor convertor(number);

  std::cout << convertor.Convert() << std::endl;

  return EXIT_SUCCESS;
}