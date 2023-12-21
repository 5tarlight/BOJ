#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int nxt = 1;
    bool nice = true;
    stack<int> s;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        q.push(a);
    }

    while (!s.empty() || !q.empty()) {
        if (!s.empty() && nxt == s.top()) {
            s.pop();
            nxt++;
            continue;
        }

        if (!q.empty()) {
            if (q.front() == nxt) {
                nxt++;
                q.pop();
            } else {
                s.push(q.front());
                q.pop();
            }
            continue;
        }

        if (!s.empty() || !q.empty()) {
            nice = false;
            break;
        }
    }

    if (nice)
        cout << "Nice";
    else
        cout << "Sad";
}
