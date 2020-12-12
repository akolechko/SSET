#pragma once
#include <string>

#include "file_in.h"
#include "file_out.h"

class TextParser {
 public:
  TextParser(FileIn *input, FileOut *output);

  long CountStr(const std::string &str);
  void ReplaceStr(const std::string &str, const std::string &to_replace);

 private:
  FileIn *input_;
  FileOut *output_;
};
