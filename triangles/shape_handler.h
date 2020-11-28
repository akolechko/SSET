#pragma once
#include <algorithm>
#include <vector>
#include "shape.h"

template<class T>
class ShapeHandler {
 public:
  void AddShape(T shape) { shapes_.push_back(shape); }

  std::vector<T> GetShapes() {
    std::vector<T> shapes = shapes_;
    return shapes;
  }

  std::vector<T> GetSortedShapes() {
    std::vector<T> shapes = shapes_;

    std::sort(shapes.begin(), shapes.end(), [](const T& a, const T& b) {
      return a.GetArea() < b.GetArea();
    });

    return shapes;
  }

 private:
  std::vector<T> shapes_;
};
