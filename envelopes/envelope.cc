#include "envelope.h"

#include <stdexcept>

Envelope::Envelope(double a, double b) { SetWidthAndHeight(a, b); }

double Envelope::GetWidth() const { return width_; }

double Envelope::GetHeight() const { return height_; }

void Envelope::SetWidthAndHeight(double a, double b) {
  if (a < 0 || b < 0) throw std::invalid_argument("Sides can't be negative.");

  if (a >= b) {
    width_ = a;
    height_ = b;
  } else {
    width_ = b;
    height_ = a;
  }
}

bool Envelope::Fits(const Envelope& envelope) {
  if (width_ <= envelope.GetWidth() && height_ <= envelope.GetHeight())
    return true;

  return false;
}