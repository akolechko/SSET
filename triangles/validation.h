#pragma once
#include "shape.h"

template <class T>
bool IsValid(const std::string &str) = delete;

template <>
bool IsValid<long>(const std::string &str) {
  errno = 0;
  char *endptr;

  (void)strtol(str.c_str(), &endptr, 0);

  if (errno != 0) {
    errno = 0;
    return 0;
  }

  if (endptr == str || *endptr != '\0') return 0;

  return 1;
}

template <>
bool IsValid<double>(const std::string &str) {
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
