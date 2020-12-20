#pragma once

class Envelope {
 public:
  Envelope(double a = 0, double b = 0);

  [[nodiscard]] std::array<double, 2> GetSize() const;
  void SetSize(double a, double b);

 private:
  std::array<double, 2> sides_;
};
