#include <iostream>

#include "conversion.h"
#include "envelope.h"

int main(int argc, char** argv) {
  if (argc != 5)
    std::cout << "Enter the width and height of two envelopes"
                 " to determine whether one suits other."
              << std::endl;
  else {
    try {
      Envelope e0(string_conversion::StringToDouble(argv[1]),
                  string_conversion::StringToDouble(argv[2]));
      Envelope e1(string_conversion::StringToDouble(argv[3]),
                  string_conversion::StringToDouble(argv[4]));

      if (e0.Fits(e1) || e1.Fits(e0))
        std::cout << "Envelopes suit each other." << std::endl;
      else
        std::cout << "Envelopes doesn't suit." << std::endl;
    } catch (const std::invalid_argument& e) {
      if (e.what() == "Sides can't be negative.")
        std::cout << e.what() << std::endl;
      else
        std::cout << "Input is invalid." << std::endl;

      return -1;
    } catch (std::out_of_range) {
      std::cout << "Sides are too big." << std::endl;

      return -1;
    }
  }

  return 0;
}