#pragma once

#include "string_convertor.h"

class NumbersView {
 public:
  NumbersView(std::ostream& out);

  void PrintIntro();
  void PrintMessage(const std::string& str);
  void PrintError(const validation::ErrorCode& error);
  void PrintConvertedNumber(const std::vector<std::string>& number);

 private:
  std::ostream& out_;
};
