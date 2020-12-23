#include "pch.h"

#include "application.h"
#include "shapes.h"
#include "string_convertor.h"
#include "string_functions.h"
#include "user_interface.h"

constexpr char delimiter[] = ",";

using EC = validation::ErrorCode;

Application::Application(int argc, char** argv) : argc_(argc), argv_(argv) {}

int Application::Run() {
  if (argc_ < 2) {
    PrintMessage("<name>, <a>, <b>, <c>");

    return EXIT_FAILURE;
  }

  std::string input;
  for (int i = 1; i < argc_; ++i) input += argv_[i];
  bool args_are_used = false;

  Shapes<Triangle> shapes;
  validation::StringConvertor convertor;
  EC error = EC::kSuccess;
  std::vector<std::string> params;
  std::vector<double> sides;
  double side = 0;
  bool flag = true;

  do {
    flag = false;
    params.clear();
    sides.clear();

    if (args_are_used)
      RequestData(input, "Enter the name and sides: ");
    else
      args_are_used = true;

    params = StringSplitter(input, delimiter);

    for (size_t i = 1; i < params.size(); ++i) {
      convertor.SetString(params[i]);
      error = convertor.StringToDouble(side);

      if (error == EC::kInvalidArgument) {
        PrintMessage("Argument is invalid.");
        flag = true;
        break;
      }

      if (error == EC::kOutOfRange) {
        PrintMessage("Argument is too big.");
        flag = true;
        break;
      }

      sides.push_back(side);
    }

    if (flag) continue;

    if (shapes.CreateAndAdd(params[0], sides) == 0) {  // Shape validation
      flag = true;
      PrintMessage("Shape is invalid. Try again.");

      continue;
    }

    std::string answer;
    RequestData(answer, "Do you want to add one more shape? (y/n): ");
    answer = ToLower(answer);
    if (answer == "y" || answer == "yes") flag = true;
  } while (flag);

  std::string class_name;
  std::vector<Triangle> sorted_shapes = shapes.GetSortedBy("a");

  if (shapes.GetClassName(class_name)) {
    PrintHeader(class_name);

    for (int i = 0; i < sorted_shapes.size(); ++i) {
      std::string number = std::to_string(i + 1);
      std::string name = sorted_shapes[i].GetName();
      std::string area = std::to_string(sorted_shapes[i].GetArea());

      PrintShape(class_name, number, name, area);
    }
  }

  return EXIT_SUCCESS;
}