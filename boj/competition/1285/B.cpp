#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        q.push(num);
    }

    vector<int> ans;
    while (!q.empty()) {
        int cur = q.top();
        q.pop();

        if (ans.empty())
            ans.push_back(cur);
        else
            ans.push_back(ans.back() / 2 + cur);

        if (cur - m > k)
            q.push(cur - m);
    }

    cout << ans.size() << '\n';
    for (int v : ans)
        cout << v << '\n';
}
