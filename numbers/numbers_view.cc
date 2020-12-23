#include "pch.h"

#include "numbers_view.h"


NumbersView::NumbersView(std::ostream& out) : out_(out) {}

void NumbersView::PrintIntro() {
  out_ << "Number to verbal representation convertor: <number>" << std::endl;
}

void NumbersView::PrintMessage(const std::string& str) {
  out_ << str << std::endl;
}

void NumbersView::PrintError(const validation::ErrorCode& error) {
  switch (error) {
    case validation::ErrorCode::kInvalidArgument:
      out_ << "Argument is invalid" << std::endl;

      break;
    case validation::ErrorCode::kOutOfRange:
      out_ << "Argument is too big" << std::endl;

      break;
  }
}

void NumbersView::PrintConvertedNumber(const std::vector<std::string>& number) {
  out_ << "Your number is:" << std::endl;

  for (std::string subnumber : number) out_ << subnumber << ' ';
}
