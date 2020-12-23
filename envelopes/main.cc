#include "pch.h"

#include "envelope.h"
#include "envelope_comparator.h"
#include "envelopes_view.h"
#include "string_convertor.h"

constexpr int kNumberOfSides = 4;

using EC = validation::ErrorCode;

int main(int argc, char** argv) {
  EnvelopesView view(std::cout);

  if (argc != kNumberOfSides + 1) {
    view.PrintIntro();

    return EXIT_FAILURE;
  }

  double side_sizes[kNumberOfSides]{};
  validation::StringConvertor convertor;
  EC error = EC::kSuccess;

  for (int i = 0; i < kNumberOfSides; ++i) {
    convertor.SetString(argv[i + 1]);
    error = convertor.StringToDouble(side_sizes[i]);

    if (error != EC::kSuccess) {
      view.PrintError(error);

      return EXIT_FAILURE;
    }

    if (side_sizes[i] < 0) {
      view.PrintMessage("Side size must not be negative");

      return EXIT_FAILURE;
    }
  }

  Envelope first(side_sizes[0], side_sizes[1]);
  Envelope second(side_sizes[2], side_sizes[3]);
  EnvelopeComparator comparator(first, second);

  view.PrintComparisonResult(comparator.Fit());

  return EXIT_SUCCESS;
}