#include "file_in.h"

#include <exception>

FileIn::FileIn(const std::string &path, const std::string &ext,
               unsigned buffer_size)
    : path_(path), extention_(ext), buffer_size_(buffer_size) {
  if (!std::filesystem::exists(path_))
    throw std::invalid_argument(path + " doesn't exist.");

  if (!path_.has_filename())
    throw std::invalid_argument(path + " must be a file.");

  if (path_.extension() != extention_)
    throw std::invalid_argument(path + " must have <" + extention_ +
                                "> extention");

  file_.open(path_, std::ios::in);
}

FileIn::~FileIn() { file_.close(); }

std::string FileIn::GetExtention() { return extention_; }

std::string FileIn::GetFileName() { return path_.filename().string(); }

std::string FileIn::GetDirectory() {
  return path_.parent_path().string() + "/";
}

bool FileIn::GetData(std::string &buffer) {
  bool end_of_file = false;
  char c;

  for (int i = 0; i < buffer_size_; ++i) {
    if (file_.get(c))
      buffer.push_back(c);
    else {
      if (buffer.empty()) end_of_file = true;
      break;
    }
  }

  return end_of_file;
}

std::string FileIn::GetPath() { return path_.string(); }

unsigned FileIn::GetBufferSize() { return buffer_size_; }

void FileIn::Close() { file_.close(); }
