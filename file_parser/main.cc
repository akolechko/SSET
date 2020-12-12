#include <cassert>
#include <iostream>

#include "file_in.h"
#include "file_out.h"
#include "text_parser.h"

constexpr int kBufferSize = 1024;
constexpr char kExtention[] = ".txt";

int main(int argc, char** argv) {
  try {
    if (argc == 3) {
      FileIn input(argv[1], kExtention, kBufferSize);
      FileOut output(input.GetDirectory(), kExtention);
      TextParser parser(&input, &output);

      std::cout << parser.CountStr(argv[2]) << std::endl;
    } else if (argc == 4) {
      FileIn input(argv[1], kExtention, kBufferSize);
      FileOut output(input.GetDirectory(), kExtention);
      TextParser parser(&input, &output);

      parser.ReplaceStr(argv[2], argv[3]);

      std::string input_path = input.GetPath();
      std::string output_path = output.GetPath();

      input.Close();
      output.Close();

      assert(std::filesystem::remove(input_path) &&
             "Input file wasn't removed.");
      std::filesystem::rename(output_path, input_path);
    } else if (argc == 5) {
      FileIn input(argv[1], kExtention, kBufferSize);
      FileOut output(argv[2], kExtention);
      TextParser parser(&input, &output);

      parser.ReplaceStr(argv[3], argv[4]);
    } else {
      std::cout
          << "String counter : <file_for_input> <string>.\n"
             "String replacer: <file_for_input> <string> <string_to_replace>.\n"
             "String replacer: <file_for_input> <file_for_output> <string> "
             "<string_to_replace>."
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