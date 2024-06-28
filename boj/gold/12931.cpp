#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n], b[n];
    fill(a, a + n, 0);

    for (int i = 0; i < n; i++)
        cin >> b[i];

    int ans = 0;
    while (true) {
        int zeros = 0;
        for (int &i : b) {
            if (i & 1) {
                ans++;
                i--;
            }
            if (i == 0)
                zeros++;
        }

        if (zeros == n)
            break;

        ans++;
        for (int &i : b)
            i /= 2;
    }

    cout << ans;
}
