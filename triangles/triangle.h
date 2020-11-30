#pragma once
#include "shape.h"

class Triangle : public Shape {
 public:
  Triangle();
  double GetArea() const;
  double GetSortedBy(const std::string &sorted_by) const;
  bool SetValidSides(std::vector<double> sides);
};
