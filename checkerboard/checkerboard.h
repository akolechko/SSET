#pragma once
#include <unordered_map>

#include "piece.h"

class Checkerboard {
 public:
  Checkerboard();
  Checkerboard(unsigned short h, unsigned short w);
  Checkerboard(const Checkerboard&) = default;

  unsigned short GetH();
  unsigned short GetW();
  void SetH(unsigned short h);
  void SetW(unsigned short w);

  void AddPiece(const std::string& position, Piece* piece);
  bool ContainsPosition(const std::string& position);
  Piece* GetPiece(const std::string& position);
  void RemovePiece(const std::string& position);

 private:
  unsigned short h_;
  unsigned short w_;
  std::unordered_map<std::string, Piece*> pieces_;
};
