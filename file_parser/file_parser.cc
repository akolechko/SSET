#include "file_parser.h"

#include <cassert>
#include <exception>
#include <filesystem>

FileParser::FileParser(const std::string& path) {
  std::filesystem::path fs_path = path;

  if (!std::filesystem::exists(fs_path))
    throw std::invalid_argument("File doesn't exist.");

  if (fs_path.extension() != ".txt")
    throw std::invalid_argument("Extention must be <.txt>.");

  file_path_ = path;
  temp_path_ =
      fs_path.parent_path().string() + fs_path.stem().string() + ".tmp";
}

FileParser::~FileParser() {
  if (file_.is_open()) file_.close();
  if (temp_.is_open()) temp_.close();
}

long FileParser::CountStr(const std::string& str) {
  file_.open(file_path_);

  long counter = 0;
  std::string line;
  size_t pos = 0;

  while (std::getline(file_, line)) {
    while (pos != std::string::npos) {
      pos = line.find(str, pos);

      if (pos != std::string::npos) {
        ++counter;
        ++pos;
      } else {
        pos = 0;

        break;
      }
    }
  }

  file_.close();

  return counter;
}

void FileParser::ReplaceStr(const std::string& str,
                            const std::string& to_replace) {
  file_.open(file_path_);
  temp_.open(temp_path_);

  std::string line;
  size_t pos = 0;

  while (std::getline(file_, line)) {
    while (pos != std::string::npos) {
      pos = line.find(to_replace);

      if (pos != std::string::npos) {
        line.replace(pos, to_replace.length(), str);
      } else {
        temp_ << line << std::endl;
        pos = 0;

        break;
      }
    }
  }

  file_.close();
  temp_.close();

  assert(std::filesystem::remove(file_path_) && "file_path_ wasn't removed.");
  std::filesystem::rename(temp_path_, file_path_);
}