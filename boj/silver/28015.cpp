#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int a[m];
        for (int j = 0; j < m; j++)
            cin >> a[j];

        int ones = 0;
        int twos = 0;

        int prev = 0;
        for (int j = 0; j <= m; j++) {
            if (a[j] == 0 || j == m) {
                if (ones == 0 && twos == 0)
                    continue;
                else if (ones != 0 && twos != 0)
                    ans += min(ones, twos) + 1;
                else
                    ans += 1;

                ones = 0;
                twos = 0;
                prev = 0;
                continue;
            }

            if (prev == 0 || prev != a[j]) {
                if (a[j] == 1)
                    ones++;
                else
                    twos++;
                prev = a[j];
            }
        }
    }

    cout << ans;
}
