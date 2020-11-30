#include "square.h"

std::string Square::GetName() const { return name_; }

std::string Square::GetClassName() const { return class_name_; }

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

double Square::GetSortedBy() const {
  if (sorted_by_ == "a") return GetArea();
  if (sorted_by_ == "p") return GetPerimeter();

  return GetArea();
}

void Square::SetName(const std::string& name) { name_ = name; }

bool Square::SetValidSides(std::vector<double> sides) {
  if (sides.size() != 1) return 0;

  sides_ = sides;

  return 1;
}

bool Square::SetSortedBy(const std::string& str) {
  if (properties_.find(str) == properties_.end()) return 0;

  sorted_by_ = str;

  return 1;
}