#pragma once
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>

class Shape {
 public:
  virtual double GetArea() const = 0;
  virtual bool SetValidSides(std::vector<double> sides) = 0;

  virtual double GetSortedBy(const std::string& sorted_by) const = 0;

  virtual std::string GetName() const { return name_; }

  virtual std::string GetClassName() const { return class_name_; }

  virtual void SetName(const std::string& name) { name_ = name; }

  virtual void SetClassName(std::string class_name) {
    class_name_ = class_name;
  }

  virtual void SetProperties(std::set<std::string> properties) {
    properties_ = properties;
  }

 protected:
  std::string name_;
  std::string class_name_;
  std::vector<double> sides_;
  std::set<std::string> properties_;
  std::string sorted_by_;
};
