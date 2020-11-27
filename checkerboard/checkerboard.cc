#include "checkerboard.h"

Checkerboard::Checkerboard() {
  h_ = 0;
  w_ = 0;
}

Checkerboard::Checkerboard(unsigned short h, unsigned short w) {
  h_ = h;
  w_ = w;
}

unsigned short Checkerboard::GetH() { return h_; }
unsigned short Checkerboard::GetW() { return w_; }
void Checkerboard::SetH(unsigned short h) { h_ = h; }
void Checkerboard::SetW(unsigned short w) { w_ = w; }

void Checkerboard::AddPiece(const std::string& position, Piece* piece) {
  pieces_[position] = piece;
}

bool Checkerboard::ContainsPosition(const std::string& position) {
  if (pieces_.find(position) == pieces_.end()) return false;
  return true;
}

Piece* Checkerboard::GetPiece(const std::string& position) {
  return pieces_[position];
}

void Checkerboard::RemovePiece(const std::string& position) {
  pieces_.erase(position);
}