#include <iostream>

int main() {
  double n;
  std::cout << "Enter n: ";
  std::cin >> n;
  n = sqrt(n);

  for (int i = 0; i < n; ++i) std::cout << i << ' ';

  return 0;
}