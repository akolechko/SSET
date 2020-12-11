#pragma once

namespace conversion {

enum class ErrorCode { kSuccess, kInvalidArgument, kOutOfRange };

ErrorCode StringToInt(const std::string &str, int &value) {
  try {
    int value_tmp = 0;
    size_t idx = 0;

    value_tmp = std::stoi(str, &idx);

    if (idx != str.length()) return ErrorCode::kInvalidArgument;

    value = value_tmp;

    return ErrorCode::kSuccess;
  } catch (std::invalid_argument) {
    return ErrorCode::kInvalidArgument;
  } catch (std::out_of_range) {
    return ErrorCode::kOutOfRange;
  }
}

ErrorCode StringToLong(const std::string &str, long &value) {
  try {
    long value_tmp = 0;
    size_t idx = 0;

    value_tmp = std::stol(str, &idx);

    if (idx != str.length()) return ErrorCode::kInvalidArgument;

    value = value_tmp;

    return ErrorCode::kSuccess;
  } catch (std::invalid_argument) {
    return ErrorCode::kInvalidArgument;
  } catch (std::out_of_range) {
    return ErrorCode::kOutOfRange;
  }
}

ErrorCode StringToUnsignedLong(const std::string &str, unsigned long &value) {
  try {
    unsigned long value_tmp = 0;
    size_t idx = 0;

    value_tmp = std::stoul(str, &idx);

    if (idx != str.length()) return ErrorCode::kInvalidArgument;

    value = value_tmp;

    return ErrorCode::kSuccess;
  } catch (std::invalid_argument) {
    return ErrorCode::kInvalidArgument;
  } catch (std::out_of_range) {
    return ErrorCode::kOutOfRange;
  }
}

ErrorCode StringToLongLong(const std::string &str, long long &value) {
  try {
    long long value_tmp = 0;
    size_t idx = 0;

    value_tmp = std::stoll(str, &idx);

    if (idx != str.length()) return ErrorCode::kInvalidArgument;

    value = value_tmp;

    return ErrorCode::kSuccess;
  } catch (std::invalid_argument) {
    return ErrorCode::kInvalidArgument;
  } catch (std::out_of_range) {
    return ErrorCode::kOutOfRange;
  }
}

ErrorCode StringToUnsignedLongLong(const std::string &str,
                                   unsigned long long &value) {
  try {
    unsigned long long value_tmp = 0;
    size_t idx = 0;

    value_tmp = std::stoull(str, &idx);

    if (idx != str.length()) return ErrorCode::kInvalidArgument;

    value = value_tmp;

    return ErrorCode::kSuccess;
  } catch (std::invalid_argument) {
    return ErrorCode::kInvalidArgument;
  } catch (std::out_of_range) {
    return ErrorCode::kOutOfRange;
  }
}

ErrorCode StringToDouble(const std::string &str, double &value) {
  try {
    double value_tmp = 0;
    size_t idx = 0;

    value_tmp = std::stod(str, &idx);

    if (idx != str.length()) return ErrorCode::kInvalidArgument;

    value = value_tmp;

    return ErrorCode::kSuccess;
  } catch (std::invalid_argument) {
    return ErrorCode::kInvalidArgument;
  } catch (std::out_of_range) {
    return ErrorCode::kOutOfRange;
  }
}

}  // namespace conversion
