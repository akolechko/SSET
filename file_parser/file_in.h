#pragma once
#include <filesystem>
#include <fstream>

class FileIn {
 public:
  FileIn(const std::string &path, const std::string &ext, unsigned buffer_size);
  ~FileIn();

  std::string GetExtention();
  std::string GetFileName();
  std::string GetDirectory();
  std::string GetPath();
  void Close();
  bool GetData(std::string &buffer);
  unsigned GetBufferSize();

 private:
  std::filesystem::path path_;
  std::string extention_;
  std::ifstream file_;
  unsigned buffer_size_;
};
