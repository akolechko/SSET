#include "pch.h"

#include "convertor.h"
#include "string_convertor.h"

using EC = validation::ErrorCode;

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Number to verbal representation convertor: <number>."
              << std::endl;

    return EXIT_FAILURE;
  }

  long long number = 0;
  validation::StringConvertor string_convertor(argv[1]);
  EC error_code = string_convertor.StringToLongLong(number);

  switch (error_code) {
    case EC::kInvalidArgument:
      std::cout << "Number is invalid." << std::endl;
      return EXIT_FAILURE;
    case EC::kOutOfRange:
      std::cout << "Number is too big." << std::endl;
      return EXIT_FAILURE;
  }

  Convertor convertor(number);

  std::cout << convertor.Convert() << std::endl;

  return EXIT_SUCCESS;
}