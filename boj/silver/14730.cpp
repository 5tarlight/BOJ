#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;

        if (b == 0)
            continue;

        ans += a * b;
    }

    cout << ans;
}
