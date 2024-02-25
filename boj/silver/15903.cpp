#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    priority_queue<long long, vector<long long>, greater<>> pq;
    while (n--) {
        int num;
        cin >> num;
        pq.push(num);
    }

    while (m--) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        pq.push(a + b);
        pq.push(a + b);
    }

    long long ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans;
}
