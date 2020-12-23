#include "pch.h"

#include "convertor.h"
#include "numbers_view.h"
#include "string_convertor.h"

using EC = validation::ErrorCode;

int main(int argc, char** argv) {
  NumbersView view(std::cout);

  if (argc != 2) {
    view.PrintIntro();

    return EXIT_FAILURE;
  }

  long long number = 0;
  validation::StringConvertor string_convertor(argv[1]);
  EC error = string_convertor.StringToLongLong(number);

  if (error != EC::kSuccess) {
    view.PrintError(error);

    return EXIT_FAILURE;
  }

  Convertor convertor(number);

  view.PrintConvertedNumber(convertor.Convert());

  return EXIT_SUCCESS;
}
