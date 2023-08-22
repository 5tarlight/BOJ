#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int a, b;
    std::cin >> a >> b;
    int result = 1;

    for (int i = a; i > a - b; i--) {
        result *= i;
    }

    for (int i = 1; i <= b; i++) {
        result /= i;
    }

    std::cout << result;
}
