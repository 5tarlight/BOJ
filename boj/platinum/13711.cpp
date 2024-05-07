#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int order[100001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    a[0] = b[0] = 0;
    for (int i = 1; i <= n; i++)
        order[b[i]] = i;
    for (int i = 1; i <= n; i++)
        a[i] = order[a[i]];

    int ans = 0;
    vector<int> lis;
    lis.push_back(-1);
    for (int i = 1; i <= n; i++) {
        if (lis.back() < a[i]) {
            lis.push_back(a[i]);
            ans++;
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), a[i]);
            *it = a[i];
        }
    }

    cout << ans;
}
