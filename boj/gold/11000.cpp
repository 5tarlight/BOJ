#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a + n);

    priority_queue<int, vector<int>, greater<>> pq;
    pq.push(a[0].second);

    for (int i = 1; i < n; i++) {
        if (pq.top() <= a[i].first)
            pq.pop();
        pq.push(a[i].second);
    }

    cout << pq.size();
}
