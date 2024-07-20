#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    long long ans = 0;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        num -= i;
        pq.push(num);

        if (pq.top() > num) {
            ans += pq.top() - num;
            pq.pop();
            pq.push(num);
        }
    }

    cout << ans;
}
