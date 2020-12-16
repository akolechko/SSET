#include "pch.h"

#include "coordinates.h"


bool Coordinates::AreValid(const CheckerBoard& board) {
  return row <= board.height && column <= board.width;
}