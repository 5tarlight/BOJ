#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    // 30 뺏으면 이김
    // 30 % (n + 1) == 0 이면 이김

    for (int i = 1; i <= n; i++) {
        if (30 % (i + 1) == 0) {
            cout << i << '\n';
        }
    }
}
