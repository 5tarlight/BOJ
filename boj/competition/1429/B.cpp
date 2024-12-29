#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, t;
    cin >> n >> t;
    queue<int> q;
    for (int i = 0; i < 2 * n; i++) {
        int num;
        cin >> num;
        q.push(num);
    }

    while (t--) {
        int x;
        cin >> x;
        x--;
        while (x--) {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }

        cout << q.front() << ' ';
    }
}
