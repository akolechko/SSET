#include "pch.h"

#include "../checkerboard/piece_arranger.h"

namespace piece_arranger {

CheckerBoard board = {8, 8};

Piece rook = {'r', {0, 0}};
Piece bishop = {'b', {7, 2}};
Piece knight = {'n', {4, 5}};

std::shared_ptr<Piece> srook = std::make_shared<Piece>(rook);
std::shared_ptr<Piece> sbishop = std::make_shared<Piece>(bishop);
std::shared_ptr<Piece> sknight = std::make_shared<Piece>(knight);

std::vector<std::shared_ptr<Piece>> pieces = {srook, sbishop, sknight};

PieceArranger arranger(board, pieces);

}  // namespace piece_arranger

TEST(TPieceArranger, Arrange) {
  std::string expected =
      "r * * * \n"
      " * * * *\n"
      "* * * * \n"
      " * * * *\n"
      "* * *n* \n"
      " * * * *\n"
      "* * * * \n"
      " *b* * *\n";

  EXPECT_EQ(expected, piece_arranger::arranger.Arrange());
}

TEST(TPieceArranger, MoveArrange) {
  piece_arranger::sknight->Move({5, 7});

  std::string expected =
      "r * * * \n"
      " * * * *\n"
      "* * * * \n"
      " * * * *\n"
      "* * * * \n"
      " * * * n\n"
      "* * * * \n"
      " *b* * *\n";

  EXPECT_EQ(expected, piece_arranger::arranger.Arrange());
}