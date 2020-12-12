#include "file_out.h"

#include <exception>

FileOut::FileOut(const std::string &path, const std::string &ext)
    : path_(path), extention_(ext) {
  if (!std::filesystem::exists(path_.parent_path()))
    throw std::invalid_argument(path + " doesn't exist.");

  if (path_.has_filename()) {
    if (path_.extension() != extention_)
      throw std::invalid_argument(path + " must have <" + extention_ +
                                  "> extention");

    file_.open(path_, std::ios::out);
  } else {
    path_ = path + "temp" + ext;

    file_.open(path_, std::ios::out);
  }
}

FileOut::~FileOut() { file_.close(); }

std::string FileOut::GetExtention() { return extention_; }

std::string FileOut::GetFileName() { return path_.filename().string(); }

std::string FileOut::GetDirectory() {
  return path_.parent_path().string() + "/";
}

std::string FileOut::GetPath() { return path_.string(); }

void FileOut::PutData(const std::string &buffer) { file_ << buffer; }

void FileOut::Close() { file_.close(); }