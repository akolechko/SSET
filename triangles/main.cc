#include <iostream>
#include "shape_handler.h"

int main() {
  ShapeHandler<Triangle> shandler;

  Triangle triangle1("Kev", 2, 2, 3);
  Triangle triangle2("Kevi", 5, 5, 9);
  Triangle triangle3("Kevin", 4, 2, 5);

  shandler.AddShape(triangle3);
  shandler.AddShape(triangle2);
  shandler.AddShape(triangle1);

  std::vector<Triangle> vec = shandler.GetSortedShapes();
  for (Triangle t : vec) std::cout << t.GetArea() << std::endl;

  return 0;
}