#pragma once
#include <iostream>

#include "checkerboard.h"
#include "piece.h"

class CBHandler {
 public:
  CBHandler(Checkerboard checkerboard);
  void SetHeightAndWidth();
  void AddPiece();
  void ShowBoard();

 private:
  Checkerboard checkerboard_;
};
