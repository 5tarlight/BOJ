#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) {
        int d, b;
        cin >> d >> b;
        a[i] = {d, b};
    }
    int l, p;
    cin >> l >> p;
    priority_queue<int, vector<int>, less<>> pq;
    sort(a, a + n);

    int ans = 0;
    int idx = 0;
    for (int i = 1; i < l; i++) {
        p--;
        if (idx < n && a[idx].first == i) {
            pq.push(a[idx].second);
            idx++;
        }

        if (p == 0) {
            if (pq.empty()) {
                cout << -1 << '\n';
                return 0;
            }
            p += pq.top();
            pq.pop();
            ans++;
        }
    }

    cout << ans;
}
