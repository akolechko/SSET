#include "pch.h"

#include "fibonacci_generator.h"
#include "string_convertor.h"
#include "fibonacci_view.h"

constexpr int kNumberOfArguments = 3;

using EC = validation::ErrorCode;

int main(int argc, char** argv) {
  FibonacciView view(std::cout);

  if (argc != kNumberOfArguments) {
    view.PrintIntro();

    return EXIT_FAILURE;
  }

  unsigned long long arguments[kNumberOfArguments-1]{};
  EC error = EC::kSuccess;
  validation::StringConvertor convertor;

  for (int i = 0; i < kNumberOfArguments - 1; ++i) {
    convertor.SetString(argv[i + 1]);
    error = convertor.StringToUnsignedLongLong(arguments[i]);

    if (error != EC::kSuccess) {
      view.PrintError(error);

      return EXIT_FAILURE;
    }
  }

  FibonacciGenerator generator(arguments[0], arguments[1]);
  view.PrintFibonacci(generator);

  return EXIT_SUCCESS;
}