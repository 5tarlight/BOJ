#include <iostream>

int main() {
  char *str = new char[1000];
  std::cin >> str;
  int index;
  std::cin >> index;
  std::cout << (char)str[index - 1];
}