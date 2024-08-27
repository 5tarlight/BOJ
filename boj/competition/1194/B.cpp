#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    long long d;
    cin >> n >> d;
    priority_queue<int, vector<int>, greater<>> mon, gear;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1)
            mon.push(b);
        else
            gear.push(b);
    }

    int ans = gear.size();
    while (!mon.empty()) {
        if (mon.top() < d) {
            d += mon.top();
            mon.pop();
            ans++;
        } else {
            while (d <= mon.top() && !gear.empty()) {
                d *= gear.top();
                gear.pop();
            }

            if (mon.top() < d) {
                d += mon.top();
                mon.pop();
                ans++;
            } else {
                break;
            }
        }
    }

    cout << ans;
}

