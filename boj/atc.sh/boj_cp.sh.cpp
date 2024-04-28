#include <iostream>
#include <deque>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int target[m];
    for (int i = 0; i < m; i++)
        cin >> target[i];
    deque<int> dq;
    for (int i = 1; i <= n; i++)
        dq.push_back(i);

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int idx = 0;
        for (int j = 0; j < dq.size(); j++) {
            if (dq[j] == target[i]) {
                idx = j;
                break;
            }
        }
        if (idx < dq.size() - idx) {
            while (dq.front() != target[i]) {
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
            dq.pop_front();
        } else {
            while (dq.front() != target[i]) {
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
            dq.pop_front();
        }
    }

    cout << cnt;
}
