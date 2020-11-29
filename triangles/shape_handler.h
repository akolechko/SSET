#pragma once
#include <algorithm>

#include "shape.h"

template <class T>
class ShapeHandler {
 public:
  std::vector<std::string> GetStrRepr() { return T::GetStrRepr(); }
  int GetSidesRequired() { return T::GetSidesRequired(); }

  void AddShape(std::string name, std::vector<double> sides) {
    T shape(name, sides);
    shapes_.push_back(shape);
  }

  std::vector<T> GetShapes() { return shapes_; }

  std::vector<T> GetSortedByArea() {
    std::vector<T> sorted_shapes = shapes_;

    std::sort(sorted_shapes.begin(), sorted_shapes.end(),
              [](const T& a, const T& b) { return a.GetArea() > b.GetArea(); });

    return sorted_shapes;
  }

  std::vector<T> GetSortedByPerimeter() {
    std::vector<T> sorted_shapes = shapes_;

    std::sort(sorted_shapes.begin(), sorted_shapes.end(),
              [](const T& a, const T& b) { return a.GetPerimeter() > b.GetPerimeter(); });

    return sorted_shapes;
  }

 private:
  std::vector<T> shapes_;
};
