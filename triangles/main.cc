#include <iostream>
#include <locale>
#include "shape_handler.h"
#include "string_handlers.h"
#include "validation.h"
#include "ui.h"

int main() {
  ShapeHandler<Triangle> shandler;
  UI ui;
  std::string str;
  std::string delimiter = ",";
  std::vector<std::string> substrings;
  std::vector<double> sides;
  bool flag = true;

  while (flag) {
    ui.RequestData(str, "[name], [a], [b], [c]: ");

    if ((substrings = StringSplitter(str, delimiter)).size() == 4) {
      flag = false;

      for (int i = 1; i < substrings.size(); ++i) {
        if (IsValid<double>(substrings[i]))
          sides.push_back(strtod(substrings[i].c_str(), nullptr));
        else
          flag = true;
      }
    }

    if (flag) {
      ui.SendMessage("Invalid input. Try again.");
      substrings.clear();
      sides.clear();
    }
    else {
      Triangle triangle(substrings[0], sides[0], sides[1], sides[2]);
      shandler.AddShape(triangle);

      substrings.clear();
      sides.clear();

      std::string answer;
      ui.RequestData(answer, "Do you want to add one more shape? (y/n): ");
      answer = ToLower(answer);
      if (answer == "y" || answer == "yes") flag = true;
    }
  }




  std::vector<Triangle> vec = shandler.GetSortedShapes();
  ui.SendMessage("============= Triangles list: ===============");
  for (int i = 0; i < vec.size(); ++i)
    std::cout << i + 1 << ". [Triangle " << vec[i].GetName()
              << "]: " << vec[i].GetArea() << " cm" << std::endl;

  return 0;
}