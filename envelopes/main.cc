#include "pch.h"

#include "envelope.h"
#include "envelope_comparator.h"
#include "string_convertor.h"

constexpr int kNumberOfSides = 4;

using EC = validation::ErrorCode;

int main(int argc, char** argv) {
  if (argc != kNumberOfSides + 1)
    std::cout << "Enter the width and height of two envelopes"
                 " to determine whether one suits other"
              << std::endl;
  else {
    double side_sizes[kNumberOfSides]{};
    EC error_code = EC::kSuccess;
    validation::StringConvertor convertor;

    for (int i = 0; i < kNumberOfSides; ++i) {
      convertor.SetString(argv[i + 1]);
      error_code = convertor.StringToDouble(side_sizes[i]);

      switch (error_code) {
        case EC::kInvalidArgument:
          std::cout << "Arguments are invalid" << std::endl;
          return EXIT_FAILURE;
        case EC::kOutOfRange:
          std::cout << "Arguments are too big" << std::endl;
          return EXIT_FAILURE;
      }

      if (side_sizes[i] < 0) {
        std::cout << "Side size must not be negative" << std::endl;
        return EXIT_FAILURE;
      }
    }

    Envelope first(side_sizes[0], side_sizes[1]);
    Envelope second(side_sizes[2], side_sizes[3]);
    EnvelopeComparator comparator(first, second);

    if (comparator.Fit())
      std::cout << "Envelopes suit each other." << std::endl;
    else
      std::cout << "Envelopes doesn't suit." << std::endl;
  }

  return EXIT_SUCCESS;
}