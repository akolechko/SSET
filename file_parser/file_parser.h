#pragma once
#include <fstream>
#include <string>

class FileParser {
 public:
  FileParser(const std::string &path);
  ~FileParser();

  long CountStr(const std::string &str);
  void ReplaceStr(const std::string &str, const std::string &to_replace);

 private:
  std::ifstream file_;
  std::ofstream temp_;
  std::string file_path_;
  std::string temp_path_;
};
