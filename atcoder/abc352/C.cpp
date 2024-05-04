#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    long long ans = 0;
    int gap[n];
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ans += a;

        gap[i] = -a + b;
    }

    sort(gap, gap + n, greater<int>());

    cout << ans + gap[0];
}
