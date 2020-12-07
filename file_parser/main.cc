#include <iostream>

#include "file_parser.h"

int main(int argc, char** argv) {
  try {
    if (argc == 3) {
      FileParser parser(argv[1]);

      std::cout << parser.CountStr(argv[2]) << std::endl;
    } else if (argc == 4) {
      FileParser parser(argv[1]);

      parser.ReplaceStr(argv[2], argv[3]);
    } else {
      std::cout
          << "String counter : <file_location> <string>.\n"
             "String replacer: <file_location> <string> <string_to_replace>"
          << std::endl;
    }
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;

    return 1;
  } catch (...) {
    std::cerr << "File system error." << std::endl;

    return 1;
  }

  return 0;
}