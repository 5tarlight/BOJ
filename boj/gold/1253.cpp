#include <iostream>
#include <algorithm>

using namespace std;

int a[2000];
bool good[2000];
int n;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int target = a[i] + a[j];

            int idx = lower_bound(a, a + n, target) - a;
            int upper = upper_bound(a, a + n, target) - a;

            if (a[idx] == target && !good[idx]) {
                for (int k = idx; k < upper; k++) {
                    if (k == i || k == j)
                        continue;
                    good[k] = true;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (good[i])
            ans++;
    cout << ans;
}
