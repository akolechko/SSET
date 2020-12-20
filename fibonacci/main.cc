#include "pch.h"

#include "fibonacci_generator.h"
#include "string_convertor.h"

using EC = validation::ErrorCode;

int main(int argc, char** argv) {
  if (argc != 3) {
    std::cout << "Enter the desired range of the fibonacci numbers: "
                 "<min> <max>"
              << std::endl;

    return EXIT_FAILURE;
  }

  unsigned long long arguments[2]{};
  EC error = EC::kSuccess;
  validation::StringConvertor convertor;

  for (int i = 0; i < 2; ++i) {
    convertor.SetString(argv[i + 1]);
    error = convertor.StringToUnsignedLongLong(arguments[i]);

    switch (error) {
      case EC::kInvalidArgument:
        std::cout << "Argument is invalid." << std::endl;
        return EXIT_FAILURE;
      case EC::kOutOfRange:
        std::cout << "Argument is too big." << std::endl;
        return EXIT_FAILURE;
    }
  }

  FibonacciGenerator generator(arguments[0], arguments[1]);

  for (; *generator <= generator.End(); ++generator) {
    std::cout << *generator << std::endl;
  }

  return EXIT_SUCCESS;
}