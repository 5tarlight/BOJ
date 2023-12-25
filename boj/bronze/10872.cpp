#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    cout << f;
}
