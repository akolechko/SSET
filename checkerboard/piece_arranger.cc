#include "piece_arranger.h"

PieceArranger::PieceArranger(const CheckerBoard &board,
                             std::vector<std::shared_ptr<Piece>> &pieces)
    : board_(board), pieces_(pieces) {}

std::string PieceArranger::Arrange() {
  std::string arranged = board_.GetStrRepr();

  std::vector<std::shared_ptr<Piece>>::iterator it = pieces_.begin();

  for (it; it != pieces_.end(); ++it) {
    unsigned long row = (*it)->GetCoordinates().row;
    unsigned long column = (*it)->GetCoordinates().column;

    unsigned long position = (board_.width + 1) * row + column;

    arranged[position] = (*it)->GetStrRepr();
  }

  return arranged;
}