#include "stdafx.h"
#include "envelope.h"

Envelope::Envelope(const double& a, const double& b) { SetSize(a, b); }

std::array<double, 2> Envelope::GetSize() const { return sides_; }

void Envelope::SetSize(const double& a, const double& b) {
  if (a < 0 || b < 0) throw std::invalid_argument("Sides can't be negative.");

  sides_ = {a, b};
  std::sort(sides_.begin(), sides_.end());
}

bool Envelope::Fits(const Envelope& envelope) {
  if (sides_[kSmallSide] <= envelope.GetSize()[kSmallSide] &&
      sides_[kBigSide] <= envelope.GetSize()[kBigSide])
    return true;

  return false;
}