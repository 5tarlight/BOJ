#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    priority_queue<int, vector<int>, less<>> present;
    cin >> n >> m;
    int child[m];
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        present.push(num);
    }
    for (int i = 0; i < m; i++)
        cin >> child[i];

    bool ok = true;
    for (int i = 0; i < m; i++) {
        int cur = child[i];

        if (present.top() < cur) {
            ok = false;
            break;
        } else {
            int left = present.top() - cur;
            present.pop();
            present.push(left);
        }
    }

    if (ok)
        cout << 1;
    else
        cout << 0;
}
