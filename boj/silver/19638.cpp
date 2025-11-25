#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n, h, t;
    cin >> n >> h >> t;

    int ans = 0;
    priority_queue<int> q;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        q.push(x);
    }

    while (t--) {
        int x = q.top();

        if (x < h) break;
        q.pop();
        q.push(max(1, x / 2));
        ans++;
    }

    if (q.top() < h) {
        cout << "YES\n" << ans;
    } else {
        cout << "NO\n" << q.top();
    }
}
