#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long n, m;
    cin >> m >> n;

    if (m * 26 < n || m > n) {
        cout << '!';
        return 0;
    }

    vector<int> ans(m, 1);
    n -= m;
    for (int i = m - 1; i >= 0; i--) {
        if (n) {
            long long d = min(25LL, n);
            n -= d;
            ans[i] += d;
        } else break;
    }

    for (auto v : ans)
        cout << (char)(v + 'A' - 1);
}
