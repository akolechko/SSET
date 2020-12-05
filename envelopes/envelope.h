#pragma once
class Envelope {
 public:
  Envelope(double a, double b);

  [[nodiscard]] double GetWidth() const;
  [[nodiscard]] double GetHeight() const;
  void SetWidthAndHeight(double a, double b);

  bool Fits(const Envelope& envelope);

 private:
  double width_;
  double height_;
};
