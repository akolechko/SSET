#include "pch.h"

#include "fibonacci_generator.h"
#include "string_convertor.h"
#include "fibonacci_view.h"


FibonacciView::FibonacciView(std::ostream& out) : out_(out) {}

void FibonacciView::PrintIntro() {
  out_ << "Enter the desired range of the fibonacci numbers: <min> <max>"
       << std::endl;
}

void FibonacciView::PrintMessage(const std::string& str) {
  out_ << str << std::endl;
}

void FibonacciView::PrintError(const validation::ErrorCode& error) {
  switch (error) {
    case validation::ErrorCode::kInvalidArgument:
      out_ << "Argument is invalid" << std::endl;

      break;
    case validation::ErrorCode::kOutOfRange:
      out_ << "Argument is too big" << std::endl;

      break;
  }
}

void FibonacciView::PrintFibonacci(FibonacciGenerator& generator) {
  out_ << "Your fibonacci numbers:" << std::endl;

  while (*generator <= generator.End()) {
    out_ << *generator;

    generator.Next();

    if (*generator <= generator.End()) out_ << ", ";
  }

  out_ << std::endl;
}
