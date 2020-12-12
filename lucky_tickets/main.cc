#include "stdafx.h"

constexpr char kExtention[] = ".txt";

int main(int argc, char** argv) {
  try {
    if (argc != 2) {
      std::cout << "Specify a method at the first line of a file: <path>."
                << std::endl;

      return EXIT_FAILURE;
    }

    std::filesystem::path path = argv[1];

    if (!std::filesystem::exists(path)) {
      std::cout << "File doesn't exist." << std::endl;

      return EXIT_FAILURE;
    }

    if (path.extension() != kExtention) {
      std::cout << "Extention must be <" << kExtention << ">." << std::endl;

      return EXIT_FAILURE;
    }

    std::ifstream file(path);
    std::string method = "";
    Ticket ticket("000000");
    std::unique_ptr<LuckinessEvaluator> evaluator;

    std::getline(file, method);

    if (method == "Moscow") {
      evaluator = std::make_unique<MoscowEvaluator>(ticket);
    } else if (method == "Piter") {
      evaluator = std::make_unique<PiterEvaluator>(ticket);
    } else {
      std::cout << "Invalid method name." << std::endl;
      file.close();

      return EXIT_FAILURE;
    }

    std::string number = "";
    int counter = 0;

    while (std::getline(file, number)) {
      ticket.SetNumber(number);
      std::cout << number << std::endl;
      evaluator->ticket = ticket;

      if (evaluator->IsLucky()) counter++;
    }

    file.close();

    std::cout << "Lucky tickets: " << counter << "." << std::endl;

    return EXIT_SUCCESS;
  } catch (const std::invalid_argument& e) {
    std::cout << e.what() << std::endl;

    return EXIT_FAILURE;
  }
}