#include <iostream>

using namespace std;

long long fact(int n) {
    if (n <= 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << fact(n);
}
