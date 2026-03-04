#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        priority_queue<long long, vector<long long>, greater<>> pq;

        for (int i = 0; i < n; i++) {
            long long x; cin >> x;
            pq.push(x);
        }

        long long ans = 1;
        while (pq.size() > 1) {
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();
            long long cost = (a * b) % 1000000007;
            ans = (ans * cost) % 1000000007;
            pq.push(a * b);
        }

        cout << ans << '\n';
    }
}
