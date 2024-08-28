#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int h, n, q;
    cin >> h >> n >> q;

    long long sum = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    while (n--) {
        int x;
        cin >> x;
        sum += x;
        pq.push(x);
    }

    while (sum - pq.top() >= h) {
        sum -= pq.top();
        pq.pop();
    }

    if (sum < h)
        cout << "-1\n";
    else
        cout << pq.size() << '\n';

    while (q--) {
        int x;
        cin >> x;
        sum += x;
        pq.push(x);

        while (sum - pq.top() >= h) {
            sum -= pq.top();
            pq.pop();
        }

        if (sum < h)
            cout << "-1\n";
        else
            cout << pq.size() << '\n';
    }
}
