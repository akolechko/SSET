#include "cbhandler.h"

#include <string>

CBHandler::CBHandler(Checkerboard checkerboard) { checkerboard_ = checkerboard; }

void CBHandler::SetHeightAndWidth() {
  unsigned short h;
  unsigned short w;

  std::cout << "Enter the height and width of the checherboard: ";
  std::cin >> h >> w;
  checkerboard_.SetH(h);
  checkerboard_.SetW(w);
}

void CBHandler::AddPiece() {
  unsigned short x;
  unsigned short y;
  bool color;
  std::string type;

  std::cout << "Enter the coordinates of the piece, color and its type: ";
  std::cin >> x >> y >> color >> type;
  std::string position = std::to_string(x) + " " + std::to_string(y);

  if (type == "r") {
    Piece* rook = new Rook;
    checkerboard_.AddPiece(position, rook);
  }
}

void CBHandler::ShowBoard() {
  unsigned short h = checkerboard_.GetH();
  unsigned short w = checkerboard_.GetW();
  std::string position;

  for (int row = 0; row < h; ++row) {
    for (int col = 0; col < w; ++col) {
      position = std::to_string(col) + " " + std::to_string(row);

      if (checkerboard_.ContainsPosition(position))
        std::cout << checkerboard_.GetPiece(position)->GetType();
      else {
        if (row % 2 == 0) {
          col % 2 == 0 ? std::cout << '*' : std::cout << ' ';
        } else {
          col % 2 == 0 ? std::cout << ' ' : std::cout << '*';
        }
        if (col == w - 1) std::cout << '\n';
      }
    }
  }
}