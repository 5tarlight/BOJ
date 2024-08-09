#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cin >> k;

    int top = a[n - 1] * k;
    int dist[top + 1];
    memset(dist, -1, sizeof(dist));
    dist[0] = 0;

    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (dist[x] == k) continue;

        for (int v : a) {
            int nxt = x + v;
            if (nxt > top || dist[nxt] != -1) continue;
            dist[nxt] = dist[x] + 1;
            q.push(nxt);
        }
    }

    for (int i = 1; i <= top; i++) {
        if (dist[i] == -1) {
            if (i % 2 == 0)
                cout << "holsoon";
            else
                cout << "jjaksoon";

            cout << " win at " << i;
            return 0;
        }
    }

    if (top % 2 == 1)
        cout << "holsoon";
    else
        cout << "jjaksoon";

    cout << " win at " << top + 1;
}
