#include "pch.h"

#include "application.h"
#include "envelope.h"
#include "envelope_comparator.h"
#include "envelopes_view.h"
#include "string_convertor.h"

constexpr int kNumberOfSides = 4;

using EC = validation::ErrorCode;

Application::Application(int argc, char** argv) : argc_(argc), argv_(argv) {}

int Application::Run() {
  EnvelopesView view(std::cout, std::cin);

  if (argc_ != kNumberOfSides + 1) {
    view.PrintIntro();

    return EXIT_FAILURE;
  }

  std::vector<std::string> input;
  for (int i = 1; i < argc_; ++i) input.push_back(argv_[i]);
  bool args_are_used = false;

  std::string answer;
  double side_sizes[kNumberOfSides]{};
  validation::StringConvertor convertor;
  EC error = EC::kSuccess;

  bool to_continue = false;
  do {
    to_continue = false;

    if (args_are_used) {
      view.PrintMessage("Enter the width and height of two envelopes:");
      for (int i = 0; i < 4; ++i) view.RequestData(input[i]);
    } else {
      args_are_used = true;
    }

    for (int i = 0; i < kNumberOfSides; ++i) {
      convertor.SetString(input[i]);
      error = convertor.StringToDouble(side_sizes[i]);

      if (error != EC::kSuccess) {
        view.PrintError(error);

        to_continue = true;
        break;
      }

      if (side_sizes[i] < 0) {
        view.PrintMessage("Side size must not be negative");

        to_continue = true;
        break;
      }
    }

    if (to_continue) continue;

    Envelope first(side_sizes[0], side_sizes[1]);
    Envelope second(side_sizes[2], side_sizes[3]);
    EnvelopeComparator comparator(first, second);

    view.PrintComparisonResult(comparator.Fit());

    view.RequestData(answer, "Do you want to continue? (y/yes): ");
    answer = ToLower(answer);
    if (answer == "y" || answer == "yes") to_continue = true;
  } while (to_continue);

  return EXIT_SUCCESS;
}

std::string Application::ToLower(const std::string& str) {
  std::string s;
  for (char ch : str) s += tolower(ch);

  return s;
}