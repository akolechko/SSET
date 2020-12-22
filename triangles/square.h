#pragma once

#include "shape.h"

class Square : public Shape {
 public:
  Square();
  double GetArea() const;
  double GetPerimeter() const;
  double GetSortedBy(const std::string &sorted_by) const;
  bool SetValidSides(std::vector<double> sides);
};