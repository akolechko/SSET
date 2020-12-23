#pragma once

#include "string_convertor.h"

class EnvelopesView {
 public:
  EnvelopesView(std::ostream& out);

  void PrintIntro();
  void PrintMessage(const std::string& str);
  void PrintError(const validation::ErrorCode& error);
  void PrintComparisonResult(bool fit);

 private:
  std::ostream& out_;
};
