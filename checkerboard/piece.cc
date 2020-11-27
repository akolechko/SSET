#include "piece.h"

unsigned short Rook::Move(unsigned short x, unsigned short y) {
  if (x == position_[0] && y != position_[1]) {
    position_[1] = y;
    // Success
    return 0;
  } else if (x != position_[0] && y == position_[1]) {
    position_[0] = x;
    // Success
    return 0;
  } else if (x == position_[0] && y == position_[1])
    // Same position
    return 1;
  else
    // Illegal
    return 2;
}

bool Rook::GetColor() { return color_; }

char Rook::GetType() { return type_; }