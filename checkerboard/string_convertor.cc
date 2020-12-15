#include "string_convertor.h"
#pragma once

namespace validation {

StringConvertor::StringConvertor(const std::string &str) : str_(str) {}

void StringConvertor::SetString(const std::string &str) { str_ = str; }

ErrorCode StringConvertor::StringToInt(int &value) {
  try {
    int value_tmp = std::stoi(str_);

    if (std::to_string(value_tmp) != str_) return ErrorCode::kInvalidArgument;

    value = value_tmp;

    return ErrorCode::kSuccess;
  } catch (std::invalid_argument) {
    return ErrorCode::kInvalidArgument;
  } catch (std::out_of_range) {
    return ErrorCode::kOutOfRange;
  }
}

ErrorCode StringConvertor::StringToLong(long &value) {
  try {
    long value_tmp = std::stol(str_);

    if (std::to_string(value_tmp) != str_) return ErrorCode::kInvalidArgument;

    value = value_tmp;

    return ErrorCode::kSuccess;
  } catch (std::invalid_argument) {
    return ErrorCode::kInvalidArgument;
  } catch (std::out_of_range) {
    return ErrorCode::kOutOfRange;
  }
}

ErrorCode StringConvertor::StringToUnsignedLong(unsigned long &value) {
  try {
    unsigned long value_tmp = std::stoul(str_);

    if (std::to_string(value_tmp) != str_) return ErrorCode::kInvalidArgument;

    value = value_tmp;

    return ErrorCode::kSuccess;
  } catch (std::invalid_argument) {
    return ErrorCode::kInvalidArgument;
  } catch (std::out_of_range) {
    return ErrorCode::kOutOfRange;
  }
}

ErrorCode StringConvertor::StringToLongLong(long long &value) {
  try {
    long long value_tmp = std::stoll(str_);

    if (std::to_string(value_tmp) != str_) return ErrorCode::kInvalidArgument;

    value = value_tmp;

    return ErrorCode::kSuccess;
  } catch (std::invalid_argument) {
    return ErrorCode::kInvalidArgument;
  } catch (std::out_of_range) {
    return ErrorCode::kOutOfRange;
  }
}

ErrorCode StringConvertor::StringToUnsignedLongLong(unsigned long long &value) {
  try {
    unsigned long long value_tmp = std::stoull(str_);

    if (std::to_string(value_tmp) != str_) return ErrorCode::kInvalidArgument;

    value = value_tmp;

    return ErrorCode::kSuccess;
  } catch (std::invalid_argument) {
    return ErrorCode::kInvalidArgument;
  } catch (std::out_of_range) {
    return ErrorCode::kOutOfRange;
  }
}

ErrorCode StringConvertor::StringToDouble(double &value) {
  try {
    double value_tmp = std::stod(str_);

    if (std::to_string(value_tmp) != str_) return ErrorCode::kInvalidArgument;

    value = value_tmp;

    return ErrorCode::kSuccess;
  } catch (std::invalid_argument) {
    return ErrorCode::kInvalidArgument;
  } catch (std::out_of_range) {
    return ErrorCode::kOutOfRange;
  }
}

}  // namespace validation