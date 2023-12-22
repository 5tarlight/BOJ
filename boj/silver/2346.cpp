#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    deque<pair<int, int>> dq; // gap, index
    for (int i = 0; i < n; i++) {
        int g;
        cin >> g;
        dq.emplace_back(g, i + 1);
    }

    while (true) {
        int gap = dq.front().first;
        cout << dq.front().second << ' ';
        dq.pop_front();

        if (dq.empty())
            break;

        if (gap > 0) {
            for (int i = 0; i < gap - 1; i++) {
                // front -> back
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            for (int i = 0; i < -gap; i++) {
                // back -> front
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
}
