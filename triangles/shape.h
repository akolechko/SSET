#pragma once
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>

class Shape {
 public:
  virtual std::string GetName() const = 0;
  virtual std::string GetClassName() const = 0;
  virtual double GetArea() const = 0;
  virtual double GetSortedBy() const = 0;
  virtual void SetName(const std::string& name) = 0;
  virtual bool SetValidSides(std::vector<double> sides) = 0;
  virtual bool SetSortedBy(const std::string& str) = 0;
};
