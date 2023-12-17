#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i * i <= n; i++) {
        ans++;
    }
    cout << ans;
}
