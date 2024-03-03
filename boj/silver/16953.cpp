#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    queue<pair<long long, int>> q; // value, dist
    q.push({a, 0});
    int ans = -1;

    while (!q.empty()) {
        long long cur = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (cur == b) {
            ans = dist + 1;
            break;
        }

        if (cur * 2 <= b) {
            q.push({cur * 2, dist + 1});
        }
        if (cur * 10 + 1 <= b) {
            q.push({cur * 10 + 1, dist + 1});
        }
    }

    cout << ans;
}
