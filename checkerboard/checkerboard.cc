#include "pch.h"

#include "checkerboard.h"

std::string CheckerBoard::GetStrRepr() {
  std::string str_repr = "";

  for (unsigned long row = 0; row < height; ++row) {
    for (unsigned long col = 0; col < width; ++col) {
      if (row % 2 == 0) {
        col % 2 == 0 ? str_repr += '*' : str_repr += ' ';
      } else {
        col % 2 == 0 ? str_repr += ' ' : str_repr += '*';
      }
      if (col == width - 1) str_repr += '\n';
    }
  }

  return str_repr;
}