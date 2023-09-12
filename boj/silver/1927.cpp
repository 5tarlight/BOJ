#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<>> q;

    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;
        if (op != 0)
            q.push(op);
        else {
            if (q.empty())
                cout << 0 << '\n';
            else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
    }
}
