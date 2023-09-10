#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ret = 1, max = 1, gap = 6;

    while (n > max) {
        max += gap;
        gap += 6;
        ++ret;
    }

    cout << ret;
}
