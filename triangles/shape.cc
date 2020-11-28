#include "shape.h"

Triangle::Triangle(const std::string &name, double side1, double side2, 
    double side3) {
  name_ = name;
  side1_ = side1;
  side2_ = side2;
  side3_ = side3;

  perimeter_ = side1_ + side2_ + side3_;
  double sp = perimeter_ / 2;
  area_ = std::sqrt(sp * (sp - side1_) * (sp - side2_) * (sp - side3_));
}

std::string Triangle::GetName() const { return name_; }

double Triangle::GetPerimeter() const { return perimeter_; }

double Triangle::GetArea() const { return area_; }
