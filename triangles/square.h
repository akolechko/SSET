#pragma once
#include "shape.h"

class Square : public Shape {
 public:
  std::string GetName() const;
  std::string GetClassName() const;
  double GetArea() const;
  double GetPerimeter() const;
  double GetSortedBy() const;
  void SetName(const std::string& name);
  bool SetValidSides(std::vector<double> sides);
  bool SetSortedBy(const std::string& str);

 private:
  std::string name_;
  std::string class_name_ = "Square";
  std::vector<double> sides_;
  std::string sorted_by_ = "a";
  std::set<std::string> properties_ = {"a", "p"};
};