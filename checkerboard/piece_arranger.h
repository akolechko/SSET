#pragma once

#include "checkerboard.h"
#include "piece.h"

class PieceArranger {
 public:
  PieceArranger(const CheckerBoard &board,
                std::vector<std::shared_ptr<Piece>> &pieces);

  std::string Arrange();

 private:
  CheckerBoard board_;
  std::vector<std::shared_ptr<Piece>> &pieces_;
};
