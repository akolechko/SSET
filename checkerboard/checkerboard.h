#pragma once
#include <string>

struct CheckerBoard {
  std::string GetStrRepr();

  unsigned long width;
  unsigned long height;
};
