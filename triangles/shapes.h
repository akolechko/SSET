#pragma once
#include "triangle.h"
#include "square.h"

template <class Shape>
class Shapes {
 public:
  bool CreateAndAdd(const std::string& name, std::vector<double> sides) {
    Shape shape;
    shape.SetName(name);

    if (shape.SetValidSides(sides) == 0) return 0;

    shapes_.push_back(shape);

    return 1;
  }

  bool GetClassName(std::string& class_name) {
    if (shapes_.size() == 0) return 0;

    class_name = shapes_[0].GetClassName();

    return 1;
  }

  std::vector<Shape> GetSorted() {
    std::vector<Shape> sorted_shapes = shapes_;

    std::sort(sorted_shapes.begin(), sorted_shapes.end(),
              [](const Shape& a, const Shape& b) {
                return a.GetSortedBy() > b.GetSortedBy();
              });

    return sorted_shapes;
  }

  bool SetSortedBy(const std::string& str) {
    if (shapes_.size() == 0) return 0;

    for (Shape v : shapes_)
      if (v.SetSortedBy(str) == 0) return 0;

    return 1;
  }

 private:
  std::vector<Shape> shapes_;
};