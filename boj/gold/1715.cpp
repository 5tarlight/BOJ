#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }

    int ans = 0;
    while (pq.size() > 1) {
        int s = pq.top();
        pq.pop();
        int nxt = pq.top();
        pq.pop();

        ans += s + nxt;
        pq.push(s + nxt);
    }

    cout << ans;
}
