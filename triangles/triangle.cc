#include "triangle.h"

std::string Triangle::GetName() const { return name_; }

std::string Triangle::GetClassName() const { return class_name_; }

double Triangle::GetArea() const {
  double area;
  double sp;  // semi-perimeter

  sp = (sides_[0] + sides_[1] + sides_[2]) / 2;
  area = std::sqrt(sp * (sp - sides_[0]) * (sp - sides_[1]) * (sp - sides_[2]));

  return area;
}

double Triangle::GetSortedBy() const {
  if (sorted_by_ == "a") return GetArea();

  return GetArea();
}

void Triangle::SetName(const std::string& name) { name_ = name; }

bool Triangle::SetValidSides(std::vector<double> sides) {
  if (sides.size() != 3) return 0;

  double a = sides[0];
  double b = sides[1];
  double c = sides[2];

  if (a + b < c) return 0;
  if (b + c < a) return 0;
  if (c + a < b) return 0;

  sides_ = sides;

  return 1;
}

bool Triangle::SetSortedBy(const std::string& str) {
  if (properties_.find(str) == properties_.end()) return 0;

  sorted_by_ = str;

  return 1;
}