#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    priority_queue<int> q;
    int n;
    cin >> n;
    n--;
    int me;
    cin >> me;
    while (n--) {
        int num;
        cin >> num;
        q.push(num);
    }

    int ans = 0;
    while (!q.empty() && me <= q.top()) {
        int t = q.top();
        q.pop();
        q.push(t - 1);
        ans++;
        me++;
    }

    cout << ans;
}
