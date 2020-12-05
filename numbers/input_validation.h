#pragma once
#include <string>

namespace input_validation {

bool IsLong(const std::string &str, int base) {
  errno = 0;
  char *endptr;

  (void)strtol(str.c_str(), &endptr, base);

  if (errno != 0) {
    errno = 0;
    return 0;
  }

  if (endptr == str || *endptr != '\0') return 0;

  return 1;
}

bool IsDouble(const std::string &str) {
  errno = 0;
  char *endptr;

  (void)strtod(str.c_str(), &endptr);

  if (errno != 0) {
    errno = 0;
    return 0;
  }

  if (endptr == str || *endptr != '\0') return 0;

  return 1;
}

}  // namespace input_validation
