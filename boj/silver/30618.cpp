#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans[n];
    int cur = 1;
    for (int i = 0; i < n / 2; i++) {
        ans[i] = cur;
        cur++;
        ans[n - i - 1] = cur;
        cur++;
    }

    if (n & 1)
        ans[n / 2] = cur;

    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}
