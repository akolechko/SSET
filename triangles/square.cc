#include "square.h"

Square::Square() {
  SetClassName("Square");
  SetProperties({"a", "p"});
}

double Square::GetArea() const {
  double area;

  area = sides_[0];

  return area;
}

double Square::GetPerimeter() const {
  double perimeter;

  perimeter = sides_[0] * 4;

  return perimeter;
}

double Square::GetSortedBy(const std::string &sorted_by) const {
  if (sorted_by == "a") return GetArea();
  if (sorted_by == "p") {
    return GetPerimeter();
  }

  return GetArea();
}

bool Square::SetValidSides(std::vector<double> sides) {
  if (sides.size() != 1) return 0;

  sides_ = sides;

  return 1;
}