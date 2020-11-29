#include "shape_handler.h"
#include "ui.h"

std::vector<std::string> Triangle::str_repr_ = {"Triangle", "Triangles"};
int Triangle::sides_required_ = 3;

std::vector<std::string> Square::str_repr_ = {"Square", "Squares"};
int Square::sides_required_ = 1;

int main() {
  ShapeHandler<Square> shandler;
  LoadData(shandler);

  std::vector<Square> sorted_shapes = shandler.GetSortedByArea();
  PrintHeader(shandler.GetStrRepr()[0]);
  for (int i = 0; i < sorted_shapes.size(); ++i) {
    std::string str_repr = shandler.GetStrRepr()[0];
    std::string number = std::to_string(i + 1);
    std::string name = sorted_shapes[i].GetName();
    std::string area = std::to_string(sorted_shapes[i].GetArea());

    PrintShape(str_repr, number, name, area);
  }

  return 0;
}