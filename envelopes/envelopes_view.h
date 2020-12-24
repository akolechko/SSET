#pragma once

#include "string_convertor.h"

class EnvelopesView {
 public:
  EnvelopesView(std::ostream& out, std::istream& in);

  void PrintIntro();
  void PrintMessage(const std::string& str);
  void PrintError(const validation::ErrorCode& error);
  void PrintComparisonResult(bool fit);
  void RequestData(std::string& str, const std::string& msg = "");

 private:
  std::ostream& out_;
  std::istream& in_;
};
