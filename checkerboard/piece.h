#pragma once

class Piece {
 public:
  virtual unsigned short Move(unsigned short x, unsigned short y) = 0;
  virtual bool GetColor() = 0;
  virtual char GetType() = 0;

 protected:
  enum Color { kBlack, kWhite };
  unsigned short position_[2];
  // 0 - black | 1 - white
  Color color_;
  char type_;
};

class Rook : public Piece {
 public:
  unsigned short Move(unsigned short x, unsigned short y);
  bool GetColor();
  char GetType();

 private:
  char type_ = 'r';
};
