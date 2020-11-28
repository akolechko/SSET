#pragma once
#include <cmath>
#include <string>
#include <iostream>

class Shape {
 public:
  virtual std::string GetName() const = 0;
  virtual double GetPerimeter() const = 0;
  virtual double GetArea() const = 0;
  
 protected:
  std::string name_;
  double perimeter_, area_;
};

class Triangle : public Shape {
 public:
  Triangle(const std::string &name, double side1, double side2, double side3);
  std::string GetName() const;
  double GetPerimeter() const;
  double GetArea() const;

 private:
  double side1_, side2_, side3_;
};
