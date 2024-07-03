#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    queue<int> q;

    for (int i = 1; i <= n; i++)
        q.push(i);

    cout << '<';
    while (!q.empty()) {
        for (int i = 0; i < k - 1; i++) {
            int c = q.front();
            q.pop();
            q.push(c);
        }

        cout << q.front();
        q.pop();

        if (!q.empty())
            cout << ", ";
    }
    cout << '>';
}
