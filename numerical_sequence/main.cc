#include "stdafx.h"

#include "big_number.h"

int main(int argc, char** argv) {
  try {
    if (argc != 3) {
      std::cout << "Enter two numbers, minimum and maximum: <min>, <max>."
                << std::endl;

      return EXIT_FAILURE;
    }

    BigNumber min = static_cast<std::string>(argv[1]);
    BigNumber max = static_cast<std::string>(argv[2]);

    for (min; min * min < max; ++min) {
      std::cout << min << std::endl;
    }

    return EXIT_SUCCESS;
  } catch (const std::invalid_argument& e) {
    std::cout << e.what() << std::endl;

    return EXIT_FAILURE;
  }
}