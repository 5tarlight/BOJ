#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> problems[n + 1];
    vector<int> entry(n + 1, 0);
    while (m--) {
        int a, b;
        cin >> a >> b;
        problems[a].push_back(b);
        entry[b]++;
    }

    priority_queue<int> q;
    for (int i = 1; i <= n; i++)
        if (entry[i] == 0)
            q.push(-i);

    while (!q.empty()) {
        int cur = -q.top();
        q.pop();

        cout << cur << ' ';

        for (int i = 0; i < problems[cur].size(); i++) {
            int target = problems[cur][i];
            entry[target]--;

            if (entry[target] == 0)
                q.push(-target);
        }
    }
}
