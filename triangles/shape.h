#pragma once
#include <cmath>
#include <string>
#include <vector>

class Shape {
 public:
  virtual std::string GetName() const = 0;
  virtual double GetPerimeter() const = 0;
  virtual double GetArea() const = 0;

 protected:
  std::string name_;
  double perimeter_, area_;
  std::vector<double> sides_;
};

// =================================================================================

class Triangle : public Shape {
 public:
  Triangle(const std::string &name, std::vector<double> sides);
  static std::vector<std::string> GetStrRepr() { return str_repr_; }
  static int GetSidesRequired() { return sides_required_; }
  std::string GetName() const;
  double GetPerimeter() const;
  double GetArea() const;

 private:
  static std::vector<std::string> str_repr_;
  static int sides_required_;
};

// =================================================================================

class Square : public Shape {
 public:
  Square(const std::string &name, std::vector<double> sides);
  static std::vector<std::string> GetStrRepr() { return str_repr_; }
  static int GetSidesRequired() { return sides_required_; }
  std::string GetName() const;
  double GetPerimeter() const;
  double GetArea() const;

 private:
  static std::vector<std::string> str_repr_;
  static int sides_required_;
};