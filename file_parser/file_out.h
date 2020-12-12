#pragma once
#include <filesystem>
#include <fstream>

class FileOut {
 public:
  FileOut(const std::string &path, const std::string &ext);
  ~FileOut();

  std::string GetExtention();
  std::string GetFileName();
  std::string GetDirectory();
  std::string GetPath();
  void Close();
  void PutData(const std::string &buffer);

 private:
  std::filesystem::path path_;
  std::string extention_;
  std::ofstream file_;
};
