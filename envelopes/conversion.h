#pragma once
#include <stdexcept>
#include <string>

namespace string_conversion {

long StringToLong(const std::string &str, int base = 10) {
  size_t idx;
  long value = std::stol(str, &idx, base);

  if (idx != str.length()) throw std::invalid_argument("Invalid input.");

  return value;
}

long StringToLongLong(const std::string &str, int base = 10) {
  size_t idx;
  long value = std::stoll(str, &idx, base);

  if (idx != str.length()) throw std::invalid_argument("Invalid input.");

  return value;
}

double StringToDouble(const std::string &str) {
  size_t idx;
  long value = std::stod(str, &idx);

  if (idx != str.length()) throw std::invalid_argument("Invalid input.");

  return value;
}

}  // namespace string_conversion
