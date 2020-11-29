#include "input_validation.h"
#include "shapes.h"
#include "string_functions.h"
#include "user_interface.h"

int main() {
  Shapes<Triangle> shapes;
  std::string delimiter = ",";
  std::string str;
  std::vector<std::string> substrings;
  std::vector<double> sides;
  bool flag = true;

  do {
    RequestData(str, "Enter the name and sides: ");

    substrings = StringSplitter(str, delimiter);

    for (int i = 1; i < substrings.size(); ++i) {
      if (IsValid<double>(substrings[i])) {
        sides.push_back(strtod(substrings[i].c_str(), nullptr));
        flag = false;
      } else {
        flag = true;
        break;
      }
    }

    if (flag) {
      PrintMessage("Input is invalid. Try again.");

      substrings.clear();
      sides.clear();

      continue;
    }

    if (shapes.CreateAndAdd(substrings[0], sides) == 0) {
      flag = true;
      PrintMessage("Shape is invalid. Try again.");

      substrings.clear();
      sides.clear();

      continue;
    }

    std::string answer;
    RequestData(answer, "Do you want to add one more shape? (y/n): ");
    answer = ToLower(answer);
    if (answer == "y" || answer == "yes") flag = true;

    substrings.clear();
    sides.clear();

  } while (flag);

  std::string class_name;
  std::vector<Triangle> sorted_shapes = shapes.GetSorted();

  if (shapes.GetClassName(class_name)) {
    PrintHeader(class_name);

    for (int i = 0; i < sorted_shapes.size(); ++i) {
      std::string number = std::to_string(i + 1);
      std::string name = sorted_shapes[i].GetName();
      std::string area = std::to_string(sorted_shapes[i].GetArea());

      PrintShape(class_name, number, name, area);
    }
  }

  return 0;
}