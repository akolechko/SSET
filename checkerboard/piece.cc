#include "pch.h"

#include "piece.h"

Piece::Piece(char str_repr, const Coordinates &coordinates)
    : str_repr_(str_repr), coordinates_(coordinates) {}

void Piece::Move(const Coordinates &coordinates) {
  coordinates_ = coordinates;
}

char Piece::GetStrRepr() { return str_repr_; }

Coordinates Piece::GetCoordinates() { return coordinates_; }
