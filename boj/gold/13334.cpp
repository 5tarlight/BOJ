#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

bool cmp(const pii &a, const pii &b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    pii a[n];
    for (int i = 0; i < n; i++) {
        int f, s;
        cin >> f >> s;
        if (f > s)
            swap(f, s);
        a[i] = { f, s };
    }
    sort(a, a + n, cmp);
    int d;
    cin >> d;

    int ans = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        int end = a[i].second;
        int start = end - d;

        while (!pq.empty() && pq.top() < start)
            pq.pop();

        if (a[i].first >= start) {
            pq.push(a[i].first);
            ans = max(ans, (int)pq.size());
        }
    }

    cout << ans;
}
