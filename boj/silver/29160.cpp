#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, less<>> pq[11];

    while (n--) {
        int p, w;
        cin >> p >> w;
        pq[p - 1].push(w);
    }

    while (k--) {
        for (int i = 0; i < 11; i++) {
            if (pq[i].empty()) continue;
            int x = pq[i].top(); pq[i].pop();
            pq[i].push(max(0, x - 1));
        }
    }

    long long ans = 0;
    for (int i = 0; i < 11; i++) {
        if (pq[i].empty()) continue;
        ans += pq[i].top();
    }

    cout << ans;
}
