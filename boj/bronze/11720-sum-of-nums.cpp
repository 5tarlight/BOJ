#include <iostream>

int main() {
  int count;
  std::cin >> count;

  char *ch = new char[count];
  std::cin >> ch;

  int sum = 0;
  for (int i = 0; i < count; i++) {
    sum += (int)ch[i] - 48;
  }

  std::cout << sum;
}
