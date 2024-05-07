#include <iostream>

int main() {
    int n;
    std::cin >> n;

    long long ans = 1;
    for (int i = n - 1; i > 1; i -= 2) {
        ans = ans * i % 1000000007;
    }

    std::cout << ans;
}
