#pragma once
#include "checkerboard.h"

struct Coordinates {
  bool AreValid(const CheckerBoard &board);

  unsigned long row;
  unsigned long column;
};
