#include "cbhandler.h"

int main() {
  // UI interface;
  // Checkboard checkerboard;
  // CBHandler handler(interface, checkerboard);

  Checkerboard checkerboard;
  CBHandler handler(checkerboard);

  handler.SetHeightAndWidth();
  handler.AddPiece();
  handler.AddPiece();
  handler.ShowBoard();

  return 0;
}
