#include "stdafx.h"
#include "conversion.h"
#include "envelope.h"

constexpr int kValidArgc = 5;

using EC = conversion::ErrorCode;

int main(int argc, char** argv) {
  try {
    if (argc != kValidArgc)
      std::cout << "Enter the width and height of two envelopes"
                   " to determine whether one suits other."
                << std::endl;
    else {
      double side_sizes[4];
      EC error_code;

      for (int i = 0; i < 4; ++i) {
        error_code = conversion::StringToDouble(argv[i + 1], side_sizes[i]);

        if (error_code == EC::kInvalidArgument) {
          std::cout << "Arguments are invalid." << std::endl;
          return EXIT_FAILURE;
        }

        if (error_code == EC::kOutOfRange) {
          std::cout << "Arguments are too big." << std::endl;
          return EXIT_FAILURE;
        }
      }

      Envelope first(side_sizes[0], side_sizes[1]);
      Envelope second(side_sizes[2], side_sizes[3]);

      if (first.Fits(second) || second.Fits(first))
        std::cout << "Envelopes suit each other." << std::endl;
      else
        std::cout << "Envelopes doesn't suit." << std::endl;
    }

    return EXIT_SUCCESS;
  } catch (const std::invalid_argument& e) {
    std::cout << e.what() << std::endl;

    return EXIT_FAILURE;
  }
}