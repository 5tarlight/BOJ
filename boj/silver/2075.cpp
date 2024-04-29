#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<>> pq;

    for (int i = 0; i < n * n; i++) {
        int x;
        cin >> x;

        if (pq.size() < n) {
            pq.push(x);
        } else {
            if (pq.top() < x) {
                pq.pop();
                pq.push(x);
            }
        }
    }

    cout << pq.top();
}
