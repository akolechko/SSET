#pragma once

class Envelope {
 public:
  Envelope(const double& a = 0, const double& b = 0);

  [[nodiscard]] std::array<double, 2> GetSize() const;
  void SetSize(const double& a, const double& b);

  bool Fits(const Envelope& envelope);

 private:
  enum SideSize { kSmallSide, kBigSide };

  std::array<double, 2> sides_;
};
