#include "shape.h"

Triangle::Triangle(const std::string &name, std::vector<double> sides) {
  name_ = name;
  sides_ = sides;

  perimeter_ = sides_[0] + sides_[1] + sides_[2];
  double sp = perimeter_ / 2;
  area_ =
      std::sqrt(sp * (sp - sides_[0]) * (sp - sides_[1]) * (sp - sides_[2]));
}

std::string Triangle::GetName() const { return name_; }

double Triangle::GetPerimeter() const { return perimeter_; }

double Triangle::GetArea() const { return area_; }

// =================================================================================

Square::Square(const std::string &name, std::vector<double> sides) {
  name_ = name;
  sides_ = sides;

  perimeter_ = sides_[0] * 4;
  area_ = sides_[0] * sides_[0];
}

std::string Square::GetName() const { return name_; }

double Square::GetPerimeter() const { return perimeter_; }

double Square::GetArea() const { return area_; }