#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        priority_queue<long long, vector<long long>, greater<>> pq;
        for (int i = 0; i < n; i++) {
            pq.push(a[i]);
        }

        long long ans = 0;
        while (pq.size() > 1) {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            ans += x + y;

            pq.push(x + y);
        }

        cout << ans << '\n';
    }
}
