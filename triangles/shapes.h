#pragma once
#include "square.h"
#include "triangle.h"

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

  std::vector<Shape> GetSortedBy(const std::string& sorted_by) {
    std::vector<Shape> sorted_shapes = shapes_;

    std::sort(sorted_shapes.begin(), sorted_shapes.end(),
              [sorted_by](const Shape& a, const Shape& b) {
                return a.GetSortedBy(sorted_by) > b.GetSortedBy(sorted_by);
              });

    return sorted_shapes;
  }

 private:
  std::vector<Shape> shapes_;
};