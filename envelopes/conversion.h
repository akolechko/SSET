#pragma once
#include <stdexcept>
#include <string>

namespace string_conversion {

long StringToLong(const std::string &str, int base = 10) {
  size_t idx;

  try {
    long value = std::stol(str, &idx, base);

    if (idx != str.length()) throw std::invalid_argument("Invalid input.");

    return value;
  } catch (std::invalid_argument) {
    throw std::invalid_argument("Invalid input.");
  } catch (std::out_of_range) {
    throw std::out_of_range("Sides are too big.");
  }
}

long long StringToLongLong(const std::string &str, int base = 10) {
  size_t idx;

  try {
    long long value = std::stoll(str, &idx, base);

    if (idx != str.length()) throw std::invalid_argument("Invalid input.");

    return value;
  } catch (std::invalid_argument) {
    throw std::invalid_argument("Invalid input.");
  } catch (std::out_of_range) {
    throw std::out_of_range("Sides are too big.");
  }
}

double StringToDouble(const std::string &str) {
  size_t idx;

  try {
    double value = std::stod(str, &idx);

    if (idx != str.length()) throw std::invalid_argument("Invalid input.");

    return value;
  } catch (std::invalid_argument) {
    throw std::invalid_argument("Invalid input.");
  } catch (std::out_of_range) {
    throw std::out_of_range("Size is incorrect.");
  }
}

}  // namespace string_conversion
