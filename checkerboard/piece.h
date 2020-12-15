#pragma once
#include <array>

#include "checkerboard.h"
#include "coordinates.h"

class Piece {
 public:
  Piece(char str_repr, const Coordinates &coordinates);

  void Move(const Coordinates &coordinates);

  char GetStrRepr();
  Coordinates GetCoordinates();

 protected:
  char str_repr_;
  Coordinates coordinates_;
};
