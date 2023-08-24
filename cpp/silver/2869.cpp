#include <iostream>

int main() {
    long long a, b, v;
    std::cin >> a >> b >> v;

    std::cout << (v - b - 1) / (a - b) + 1;
}
