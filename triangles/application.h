#pragma once

class Application {
 public:
  Application(int argc, char** argv);

  int Run();

 private:
  int argc_;
  char** argv_;
};
