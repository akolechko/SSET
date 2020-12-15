#pragma once
#include <string>
#include <stdexcept>

namespace validation {

enum class ErrorCode { kSuccess, kInvalidArgument, kOutOfRange };

class StringConvertor {
 public:
  StringConvertor(const std::string &str = "");

  void SetString(const std::string &str);

  ErrorCode StringToInt(int &value);
  ErrorCode StringToLong(long &value);
  ErrorCode StringToUnsignedLong(unsigned long &value);
  ErrorCode StringToLongLong(long long &value);
  ErrorCode StringToUnsignedLongLong(unsigned long long &value);
  ErrorCode StringToDouble(double &value);

 private:
  std::string str_;
};

}  // namespace conversion