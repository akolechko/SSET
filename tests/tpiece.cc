#include "pch.h"

#include "../checkerboard/piece.h"

TEST(TPiece, Move) {
  unsigned long expected_row = 20;
  unsigned long expected_column = 15;

  Piece piece('r', {25, 20});
  piece.Move({expected_row, expected_column});

  Coordinates result = piece.GetCoordinates();
  unsigned long result_row = result.row;
  unsigned long result_column = result.column;

  EXPECT_EQ(expected_row, result_row);
  EXPECT_EQ(expected_column, result_column);
}

TEST(TPiece, GetStrRepr) {
  Piece piece('r', {25, 20});

  EXPECT_EQ('r', piece.GetStrRepr());
}