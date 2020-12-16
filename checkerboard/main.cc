#include "pch.h"

#include "checkerboard.h"
#include "coordinates.h"
#include "piece.h"
#include "piece_arranger.h"
#include "string_convertor.h"

int main(int argc, char** argv) {
  if (argc != 6) {
    std::cout << "<board_h> <board_w> <piece_row> <piece_col> <piece_repr>"
              << std::endl;

    return EXIT_FAILURE;
  }

  std::string piece_repr = argv[5];

  if (piece_repr.length() != 1) {
    std::cout << "piece_repr must be one character." << std::endl;

    return EXIT_FAILURE;
  }

  unsigned long arguments[4];
  validation::StringConvertor convertor;

  for (int i = 0; i < 4; ++i) {
    convertor.SetString(argv[i + 1]);
    validation::ErrorCode error = convertor.StringToUnsignedLong(arguments[i]);

    if (error != validation::ErrorCode::kSuccess) {
      if (error == validation::ErrorCode::kInvalidArgument)
        std::cout << "Argument is invalid." << std::endl;
      if (error == validation::ErrorCode::kOutOfRange)
        std::cout << "Argument is too big." << std::endl;

      return EXIT_FAILURE;
    }
  }

  CheckerBoard board = {arguments[0], arguments[1]};
  Coordinates coordinates = {arguments[2], arguments[3]};

  if (!coordinates.AreValid(board)) {
    std::cout << "Piece coordinates are invalid." << std::endl;

    return EXIT_FAILURE;
  }

  std::shared_ptr<Piece> piece =
      std::make_shared<Piece>(piece_repr[0], coordinates);
  std::vector<std::shared_ptr<Piece>> pieces;
  pieces.push_back(piece);

  PieceArranger arranger(board, pieces);

  std::cout << arranger.Arrange();

  return EXIT_SUCCESS;
}